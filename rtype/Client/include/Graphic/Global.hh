//
// global.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Mon Oct 28 15:04:47 2013 cyril jourdain
// Last update Sun Nov 24 16:54:42 2013 cyril jourdain
//

#ifndef 		__GLOBAL_HH__
# define 		__GLOBAL_HH__

// WINDOWS
#define			WIN_X 1280
#define			WIN_Y 720

// WINDOWS ID
#define			LOGIN 0
#define			LOBBY 1
#define			GAME 2
#define			GAMEOVER 3

// RESSOURCES
#define			LOGIN_BACKGROUND_RES		"./Res/background.jpg"
#define			LOGIN_BACKGROUND		"loginbackground"
#define			LOGIN_BUTTON_IMAGE_RES		"./Res/ConnectButton.png"
#define			LOGIN_BUTTON_IMAGE		"loginButton"
#define			LOGIN_BACKGROUND_BOX_RES	"./Res/login_box.png"
#define			LOGIN_BACKGROUND_BOX		"loginBackgroundBox"
#define			LOBBY_BACKGROUND_RES		"./Res/lobby_background.jpg"
#define			LOBBY_BACKGROUND		"lobbyBackground"
#define			LOBBY_CENTER_BOX_RES		"./Res/lobby_center_box.png"
#define			LOBBY_CENTER_BOX		"lobbyCenterBox"
#define			LOBBY_JOIN_BUTTON_RES		"./Res/join_button.png"
#define			LOBBY_JOIN_BUTTON		"lobbyJoinButton"
#define			LOBBY_CREATE_BUTTON_RES		"./Res/create_button.png"
#define			LOBBY_CREATE_BUTTON		"lobbyCreateButton"
#define			LOBBY_REFRESH_BUTTON_RES	"./Res/refresh_button.png"
#define			LOBBY_REFRESH_BUTTON		"lobbyRefreshButton"
#define			LOBBY_BACK_BUTTON_RES		"./Res/back_button.png"
#define			LOBBY_BACK_BUTTON		"lobbyBackButton"
#define			DIALOGBOX_BACKGROUND_RES	"./Res/dialogbox_background.png"
#define			DIALOGBOX_BACKGROUND		"dialogBoxBackground"
#define			DIALOGBOX_OK_BUTTON_RES		"./Res/dialogbox_ok_button.png"
#define			DIALOGBOX_OK_BUTTON		"dialogboxOkButton"
#define			DIALOGBOX_CANCEL_BUTTON_RES	"./Res/dialogbox_cancel_button.png"
#define			DIALOGBOX_CANCEL_BUTTON		"dialogboxCancelButton"
#define			ARRAY_BACKGROUND_RES		"./Res/lobby_array_background2.png"
#define			ARRAY_BACKGROUND		"arrayBackground"
#define			LOBBY_ARRAY_BACKGROUND_RES	"./Res/lobby_array_background.png"
#define			LOBBY_ARRAY_BACKGROUND		"lobbyArrayBackground"
#define			ARRAY_LINE_PART_RES		"./Res/array_cell.png"
#define			ARRAY_LINE_PART			"arrayLinePart"
#define			ARRAY_LINE_PART_SELECTED_RES	"./Res/array_cell_selected.png"
#define			ARRAY_LINE_PART_SELECTED	"arrayLinePartSelected"
#define			GAME_BACKGROUND_RES		"./Res/game_background.jpg"
#define			GAME_BACKGROUND			"gameBackground"
#define			GAME_BACKGROUND2		"gameBackground2"
#define			GAMEOVER_BACKGROUND_RES		"./Res/gameOver_background.jpg"
#define			GAMEOVER_BACKGROUND		"gameOverBackground"
#define			GAME_HUD_RES			"./Res/game_hud.png"
#define			GAME_HUD			"gameHUD"
#define			GAME_HUD_LIVES_RES		"./Res/game_lives.png"
#define			GAME_HUD_LIVES			"game_lives"

/* ********** SPRITES ********* */
#define			SPRITE_PLAYER1_CONF		"./Res/Sprites/player1.sprite"
#define			SPRITE_PLAYER1		        "player1"
#define			SPRITE_PLAYER2_CONF		"./Res/Sprites/player2.sprite"
#define			SPRITE_PLAYER2		        "player2"
#define			SPRITE_PLAYER3_CONF		"./Res/Sprites/player3.sprite"
#define			SPRITE_PLAYER3		        "player3"
#define			SPRITE_PLAYER4_CONF		"./Res/Sprites/player4.sprite"
#define			SPRITE_PLAYER4		        "player4"
#define			SPRITE_MOB1_CONF		"./Res/Sprites/mob1.sprite"
#define			SPRITE_MOB1		        "mob1"
#define			SPRITE_ROCKET_CONF		"./Res/Sprites/rocket.sprite"
#define			SPRITE_ROCKET			"rocket"
#define			SPRITE_ROCKET2_CONF		"./Res/Sprites/rocket2.sprite"
#define			SPRITE_ROCKET2			"rocket2"
#define			SPRITE_WALLD1_CONF		"./Res/Sprites/walld1.sprite"
#define			SPRITE_WALLD1			"walld1"
#define			SPRITE_WALLD2_CONF		"./Res/Sprites/walld2.sprite"
#define			SPRITE_WALLD2			"walld2"
#define			SPRITE_WALLD3_CONF		"./Res/Sprites/walld3.sprite"
#define			SPRITE_WALLD3			"walld3"
#define			SPRITE_WALLD4_CONF		"./Res/Sprites/walld4.sprite"
#define			SPRITE_WALLD4			"walld4"
#define			SPRITE_WALLD5_CONF		"./Res/Sprites/walld5.sprite"
#define			SPRITE_WALLD5			"walld5"
#define			SPRITE_WALLU1_CONF		"./Res/Sprites/wallu1.sprite"
#define			SPRITE_WALLU1			"wallu1"
#define			SPRITE_WALLU2_CONF		"./Res/Sprites/wallu2.sprite"
#define			SPRITE_WALLU2			"wallu2"
#define			SPRITE_WALLU3_CONF		"./Res/Sprites/wallu3.sprite"
#define			SPRITE_WALLU3			"wallu3"
#define			SPRITE_WALLU4_CONF		"./Res/Sprites/wallu4.sprite"
#define			SPRITE_WALLU4			"wallu4"
#define			SPRITE_WALLU5_CONF		"./Res/Sprites/wallu5.sprite"
#define			SPRITE_WALLU5			"wallu5"
#define			SPRITE_WALL1D1_CONF		"./Res/Sprites/wall1d1.sprite"
#define			SPRITE_WALL1D1			"wall1d1"
#define			SPRITE_WALL1D2_CONF		"./Res/Sprites/wall1d2.sprite"
#define			SPRITE_WALL1D2			"wall1d2"
#define			SPRITE_WALL1D3_CONF		"./Res/Sprites/wall1d3.sprite"
#define			SPRITE_WALL1D3			"wall1d3"
#define			SPRITE_WALL1D4_CONF		"./Res/Sprites/wall1d4.sprite"
#define			SPRITE_WALL1D4			"wall1d4"
#define			SPRITE_WALL1D5_CONF		"./Res/Sprites/wall1d5.sprite"
#define			SPRITE_WALL1D5			"wall1d5"
#define			SPRITE_WALL1U1_CONF		"./Res/Sprites/wall1u1.sprite"
#define			SPRITE_WALL1U1			"wall1u1"
#define			SPRITE_WALL1U2_CONF		"./Res/Sprites/wall1u2.sprite"
#define			SPRITE_WALL1U2			"wall1u2"
#define			SPRITE_WALL1U3_CONF		"./Res/Sprites/wall1u3.sprite"
#define			SPRITE_WALL1U3			"wall1u3"
#define			SPRITE_WALL1U4_CONF		"./Res/Sprites/wall1u4.sprite"
#define			SPRITE_WALL1U4			"wall1u4"
#define			SPRITE_WALL1U5_CONF		"./Res/Sprites/wall1u5.sprite"
#define			SPRITE_WALL1U5			"wall1u5"
#define			EXPLOSION_CONF			"./Res/explosion.sprite"
#define			EXPLOSION			"explosion"


/* *********** FONT ***********/

#define			ARIAL_FONT_RES			"./Res/arial.ttf"
#define			ARIAL_FONT			"arial"

#endif
