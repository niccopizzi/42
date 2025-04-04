/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:31:07 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/08 14:27:01 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philosopher *phil, t_param_data *data,
		size_t starting_milliseconds, int phil_num)
{
	if ((phil_num % 2 == 0))
	{
		pthread_mutex_lock(&phil->next->fork_mutex);
		locked_printing(starting_milliseconds, phil_num, data,
			"has taken a fork");
		pthread_mutex_lock(&phil->fork_mutex);
		locked_printing(starting_milliseconds, phil_num, data,
			"has taken a fork");
	}
	else
	{
		ft_usleep(1, data);
		pthread_mutex_lock(&phil->fork_mutex);
		locked_printing(starting_milliseconds, phil_num, data,
			"has taken a fork");
		pthread_mutex_lock(&phil->next->fork_mutex);
		locked_printing(starting_milliseconds, phil_num, data,
			"has taken a fork");
	}
	return (0);
}

void	sleep_routine(size_t starting_milliseconds, size_t sleep_time,
		t_philosopher *philo, t_param_data *data)
{
	int	phil_num;

	phil_num = philo->philosopher_num;
	locked_printing(starting_milliseconds, phil_num, data, "is sleeping");
	ft_usleep(sleep_time, data);
	locked_printing(starting_milliseconds, phil_num, data, "is thinking");
	ft_usleep(1, data);
	if (read_or_update_death(data, 'r') == false)
		dinner((void *)philo);
}

void	*dinner(void *philosopher_head)
{
	t_philosopher	*phil;
	t_param_data	*data;
	int				phil_num;
	size_t			starting_milliseconds;

	phil = (t_philosopher *)philosopher_head;
	data = phil->data;
	starting_milliseconds = phil->data->starting_milliseconds;
	phil_num = phil->philosopher_num;
	take_forks(phil, data, starting_milliseconds, phil_num);
	locked_printing(starting_milliseconds, phil_num, data, "is eating");
	pthread_mutex_lock(&phil->data->update_mutex);
	phil->last_meal = get_time_in_milliseconds();
	phil->spaghetti_eaten += 1;
	pthread_mutex_unlock(&phil->data->update_mutex);
	ft_usleep(data->eat_time, data);
	pthread_mutex_unlock(&phil->fork_mutex);
	pthread_mutex_unlock(&phil->next->fork_mutex);
	if (phil->spaghetti_eaten == data->how_many_spaghetti)
		return (NULL);
	if (read_or_update_death(data, 'r') == false)
		sleep_routine(starting_milliseconds, data->sleep_time, phil, data);
	return (NULL);
}
