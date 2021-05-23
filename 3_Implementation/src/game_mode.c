/**
 * @file game_mode.c
 * @author Vivek Kumar Yadav - 99004434(vivek.yadav@ltts.com)
 * @brief funtion definitions of each player mode options
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "matrix.h"
/**
 * @brief funtion definitions of player vs player mode options
 * 
 * @param s 
 * @param list 
 * @param key 
 * @param lock 
 * @return int 
 */

int	player_vs_player(t_struct *s, t_list *list, int key, int lock)
{
  while (lock != 3 && (key = getch()))
    if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT ||
	key == KEY_RIGHT || key == SPACE || key == ENTER || key == 's')
      {
	if ((key == KEY_UP || key == KEY_DOWN) && lock != 2)
	  move_up_down(s, list, key);
	      if (key == KEY_LEFT || key == KEY_RIGHT)
		move_left_right(s, list, key);
	      if (key == SPACE)
		select_pos(s, list, &lock);
	      if (key == ENTER)
		delete_selected(s, &list, &lock);
	      if (key == 's')
		lets_take_a_screenshot(s, list);
      }
  return (0);
}
/**
 * @brief 
 * 
 * @param s 
 * @param list 
 * @param key 
 * @param lock 
 */
void	player_vs_bot(t_struct *s, t_list *list, int key, int lock)
{
  while (lock != 3)
    if (s->turn == 2)
      {
	while (lock != 3 && s->turn == 2 && (key = getch()))
	  if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT ||
	      key == KEY_RIGHT || key == SPACE || key == ENTER || key == 's')
	    {
	      if ((key == KEY_UP || key == KEY_DOWN) && lock != 2)
		move_up_down(s, list, key);
	      if (key == KEY_LEFT || key == KEY_RIGHT)
		move_left_right(s, list, key);
	      if (key == SPACE)
		select_pos(s, list, &lock);
	      if (key == ENTER)
		delete_selected(s, &list, &lock);
	      if (key == 's')
                lets_take_a_screenshot(s, list);
	    }
      }
    else
      {
	lock = 1;
	lvl_check(s, list);
	delete_selected(s, &list, &lock);
      }
}

int	bot_vs_bot(t_struct *s, t_list *list, int lock)
{
  while (lock != 3)
    {
      if (s->turn == 2)
	{
	  lock = 1;
	  lvl_check(s, list);
	  delete_selected(s, &list, &lock);
	}
      else
	{
	  lock = 1;
          lvl_check(s, list);
          delete_selected(s, &list, &lock);
	}
    }
  return (0);
}
