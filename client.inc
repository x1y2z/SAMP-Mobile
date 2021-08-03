/* by x1y2z for developers
Do not need anything, just include to your gamemode*/

#if defined included
	#endinput
#endif
#define included

#tryinclude <a_samp>

#if !defined gpci
    native gpci(playerid, buffer[], size = sizeof(buffer));
#endif

#define AUTH_KEY     "4458465947454248504B51425156534F4738384F"

new bool:bIsFromMobile[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
    new gpciStr[64];
    gpci(playerid, gpciStr);
    if(!strcmp(gpciStr, AUTH_KEY))
	    bIsFromMobile[playerid] = true;
	else
	    bIsFromMobile[playerid] = false;
    #if defined mobile_OnPlayerConnect
		return mobile_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect mobile_OnPlayerConnect
#if defined mobile_OnPlayerConnect
	forward mobile_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
    bIsFromMobile[playerid] = false;
    #if defined mobile_OnPlayerDisconnect
		return mobile_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect mobile_OnPlayerDisconnect
#if defined mobile_OnPlayerDisconnect
	forward mobile_OnPlayerDisconnect(playerid, reason);
#endif

stock bool:IsMobile(playerid)
{
    return bIsFromMobile[playerid];
}