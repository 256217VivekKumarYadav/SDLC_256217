#ifndef MATRIX_H_
# define MATRIX_H_

# define ENTER 10
# define ESCAPE 27
# define SPACE 32
# define YMIN 5
# define YMAX 17
# define XMIN 24

# include <stdlib.h>
# include <ncurses.h>
# include <curses.h>

typedef struct	s_list
{
  int		x;
  int		y;
  int		pos;
  int		selec;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_struct
{
  WINDOW	*game;
  int		mode;
  int		lvl;
  int		line;
  int		al_per_line;
  int		turn;
}		t_struct;


int	color_print_nb(WINDOW *w, int y, int x, int key);

/**
 * @brief Dispalys the winner in the game 
 * 
 */
int	show_win(t_struct *s, int tm);

int	print_opti(t_struct *s, t_list *list);

/**
 * @brief Dispalys the turn to play
 * 
 */
int	print_list(t_struct *s, t_list *list, int i);

int	l_allum(t_list *list, int y);

/**
 * @brief Deletes the element in the list
 * 
*/
int	marienbad_del(t_struct *s, t_list *list, int i, int y);

int	marienbad(t_struct *s, t_list *list, int i, int y);

/**
 * @brief Checks the difficulty level
 * 
 */
int	lvl_check(t_struct *s, t_list *list);

/**
 * @brief Creates the size of list 
 * 
 */
int	list_size(t_list *list);

/**
 * @brief Deletes the list w
 * 
 */
int	delete_list(t_list **list);

int	add_elem_next(t_list **list, int x, int y);

int	ini_list(t_list **list, int x, int y);

/**
 * @brief Move in left and right direction
 * 
 */
int	move_left_right(t_struct *s, t_list *list, int key);

/**
 * @brief Choose the level of game 
 * 
 */
int	chose_lvl(t_struct *s, int key);

/**
 * @brief Instructions of the game for user
 * 
 */
int	chose_alum_nb(t_struct *s, int key, int i, int choice);

/**
 * @brief Builds the list of elements
 * 
 */
int	build_list(t_struct *s, int x, int y, int max);

/**
 * @brief Selects the maximum number of elemnts in list
 * 
 */
int	case_marienbad(t_struct *s, t_list *list);
/**
 * @brief Dispalys the options of different modes 
 * 
 */
int	chose_game_mode(t_struct *s, int key);

/**
 * @brief Game between two players
 * 
 */
int	player_vs_player(t_struct *s, t_list *list, int key, int lock);

/**
 * @brief Game between Computer and a player
 * 
 */
void	player_vs_bot(t_struct *s, t_list *list, int key, int lock);

/**
 * @brief Game between two compuetrs
 * 
 */
int	bot_vs_bot(t_struct *s, t_list *list, int lock);

/**
 * @brief Keys to move directions
 * 
 */
int	move_up_down(t_struct *s, t_list *list, int key);

/**
 * @brief Loads the game
 * 
 */
int	game_prep(t_struct *s, t_list *list);

/**
 * @brief Deletes the selected list in the game
 * 
 */
int	delete_selected(t_struct *s, t_list **list, int *lock);

/**
 * @brief Position is selected 
 * 
 */
int	select_pos(t_struct *s, t_list *list, int *lock);

int	my_putstr(char *str, int output);

int	print_videorev(WINDOW *w, int y, int x, char *str);

int	print_whereami_notselect(WINDOW *w, int y, int x, char *str);

/**
 * @brief Displays the cursor position
 * 
 */
int	print_whereami(WINDOW *w, int y, int x, char *str);

/**
 * @brief To quit the game
 * 
 */
void	just_quit(t_struct *s);

/**
 * @brief Calculates the number of lines which game is being played
 * 
 */
int	calc_nb_lines(t_list *tmp, t_list *list, int i);

/**
 * @brief Console interface
 * 
 */
int	config_print(WINDOW *w, t_list *list);

/**
 * @brief Chooses the structure of games i.e rectangle or pyramid
 * 
 */
int	chose_game_structure(t_struct *s, int key, int choice);

int	chose_alum_per_line(t_struct *s, int key, int i);

int	build_list_rectangle(t_struct *s, int x, int y, int i);

/**
 * @brief Takes a screenshot in the game if user intends
 * 
 */
int	lets_take_a_screenshot(t_struct *s, t_list *list);

int	print_screenshot(WINDOW *w, char *str);

/**
 * @brief Dealloactes the memory after the game complters
 * 
 */
char	**my_double_malloc(char **str, int sizeb, int size);

int	my_double_free(char **str);

#endif /* !MATRIX_H_ */
