#if defined _armsfix_plus_included
  #endinput
#endif
#define _armsfix_plus_included


enum AF_UpdateReason {
	AF_PlayerSpawned	= 0,
	AF_PluginRequested	= 1,
};

/*********************************************************
 * Called when arms updated
 *
 * @param client		The client index of the player
 * @param res			Update reason
 * @no return
 *********************************************************/
forward void AF_OnArmsUpdate(int client, AF_UpdateReason res);

/*********************************************************
 * Get ArmsFix+ version
 *
 * @return              Version number
 *********************************************************/
native int AF_Version();

/*********************************************************
 * Change default arms models for team "team"
 *
 * @param team          Team index (CS_TEAM_CT=3 or CS_TEAM_T=2)
 * @no return
 *********************************************************/
native void AF_SetTeamDefaultArmsModel(int team, char[] mdl_path);


/*********************************************************
 * Is client using custom arms model
 *
 * @param client        Client index (not userid)
 * @return              true is client using custom arms model
 *********************************************************/
native bool AF_HasClientCustomArms(int client);


/*********************************************************
 * Change client arms models
 *
 * @param client        Client index (not userid)
 * @param mdl_path      String path to the model (maxlen=192 including zero terminator)
 * @no return
 *********************************************************/
native void AF_SetClientArmsModel(int client, char[] mdl_path);


/*********************************************************
 * Simply remove custom arms model (like on player model change)
 *
 * @param client        Client index (not userid)
 * @no return
 *********************************************************/
native void AF_RemoveClientArmsModel(int client);


/*********************************************************
 * Get player arms model
 *
 * @param client        Client index (not userid)
 * @param dest          Destination string
 * @param maxlen        Destination string length
 * @return              Number of bytes written
 *********************************************************/
native int AF_GetClientArmsModel(int client, char[] dest, int maxlen);


/*********************************************************
 * Get player arms model
 *
 * @param team          Team index (CS_TEAM_CT=3 or CS_TEAM_T=2)
 * @param dest          Destination string
 * @param maxlen        Destination string length
 * @return              Number of bytes written
 *********************************************************/
native int AF_GetTeamArmsModel(int team, char[] dest, int maxlen);


/*********************************************************
 * Simply SET arms model (like on player model change)
 *
 * @param client        Client index (not userid)
 * @return              true is changed to custom, false otherwise
 *********************************************************/
native bool AF_RequestArmsUpdate(int client);


/*********************************************************
 * Disable arms updating (usable for gloves plugin with gloves's own arms)
 *
 * @param client        Client index (not userid)
 * @param disable       true to disable updating, true to enable updating
 * @param remove_arms   true to remove arms on disable
 * @no return
 *********************************************************/
native void AF_DisableClientArmsUpdate(int client, bool disable = true, bool remove_arms = true);


public Extension __ext_armsfix_plus = 
{
	name = "ArmsFix_Plus",
	file = "ArmsFix_Plus.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public __ext_armsfix_plus_SetNTVOptional()
{
	MarkNativeAsOptional("AF_Version");
	MarkNativeAsOptional("AF_SetTeamDefaultArmsModel");
	MarkNativeAsOptional("AF_HasClientCustomArms");
	MarkNativeAsOptional("AF_SetClientArmsModel");
	MarkNativeAsOptional("AF_RemoveClientArmsModel");
	MarkNativeAsOptional("AF_GetClientArmsModel");
	MarkNativeAsOptional("AF_GetTeamArmsModel");
	MarkNativeAsOptional("AF_RequestArmsUpdate");
	MarkNativeAsOptional("AF_DisableClientArmsUpdate");
}
#endif