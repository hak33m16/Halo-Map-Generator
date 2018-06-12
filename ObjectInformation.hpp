#ifndef OBJECT_INFORMATION_HPP_
#define OBJECT_INFORMATION_HPP_

#include <SFML/System.hpp>
#include <map>

std::map<sf::Uint32, std::string> _ITEMMAP =
{        
		{ 11970, "TWO-WAY"},
        { 11969, "RECEIVER"},
        { 11968, "SENDER"},
        { 17489, "SENDER, VEHICLE ONLY"},
        { 17490, "RECEIVER, VEHICLE ONLY"},
        { 17491, "TWO-WAY, VEHICLE ONLY"},
        { 17486, "SENDER, VEHICLE"},
        { 17487, "RECEIVER, VEHICLE"},
        { 17488, "TWO-WAY, VEHICLE"},
        { 5402, "BANSHEE"},
        { 5400, "CHOPPER"},
        { 23145, "ELEPHANT"},
        { 5399, "GHOST"},
        { 5528, "HORNET"},
        { 5531, "HORNET, LITE"},
        { 5526, "MONGOOSE"},
        { 21376, "PROWLER"},
        { 5408, "SCORPION"},
        { 5398, "SHADE TURRET"},
        { 5407, "WARTHOG"},
        { 17473, "WARTHOG, GAUSS"},
        { 17474, "WARTHOG, TROOP"},
        { 17475, "WARTHOG, CIVILIAN"},
        { 17479, "WARTHOG, DISABLED"},
        { 5529, "WARTHOG, SNOW"},
        { 17476, "WARTHOG, SNOW, GAUSS"},
        { 17477, "WARTHOG, SNOW, TROOP"},
        { 17478, "WARTHOG, SNOW, CIVILIAN"},
        { 17480, "WARTHOG, SNOW, DISABLED"},
        { 5401, "WRAITH"},
        { 17481, "WRAITH, ANTI-AIR"},
        { 5385, "BEAM RIFLE"},
        { 5375, "BRUTE SHOT"},
        { 5534, "ENERGY SWORD"},
        { 6741, "FLAMETHROWER"},
        { 5369, "FUEL ROD GUN"},
        { 5388, "GRAVITY HAMMER"},
        { 5368, "NEEDLER"},
        { 5413, "PLASMA RIFLE"},
        { 5520, "PLASMA RIFLE, POWER"},
        { 5555, "ROCKET LAUNCHER"},
        { 6742, "SENTINEL BEAM"},
        { 6725, "SHOTGUN"},
        { 5553, "SNIPER RIFLE"},
        { 5554, "SPARTAN LASER"},
        { 5376, "SPIKER"},
        { 10316, "MACHINE GUN TURRET"},
        { 5557, "MACHINE GUN TURRET, DETACHED"},
        { 5371, "PLASMA CANNON"},
        { 5390, "PLASMA CANNON, DETACHED"},
        { 14872, "MISSILE POD"},
        { 6740, "MISSILE POD, DETACHED"},
        { 5380, "MAULER"},
        { 5522, "MAULER, POWER"},
        { 5502, "MAGNUM"},
        { 5523, "MAGNUM, DAMAGE"},
        { 5524, "MAGNUM, POWER"},
        { 5367, "PLASMA PISTOL"},
        { 5525, "PLASMA PISTOL, POWER"},
        { 5374, "COVENANT CARBINE"},
        { 5572, "COVENANT CARBINE, ACCURACY"},
        { 5569, "COVENANT CARBINE, AMMO"},
        { 5571, "COVENANT CARBINE, DAMAGE"},
        { 5521, "COVENANT CARBINE, POWER"},
        { 5570, "COVENANT CARBINE, RANGE"},
        { 5568, "COVENANT CARBINE, RATE OF FIRE"},
        { 5504, "DMR"},
        { 5512, "DMR, ACCURACY"},
        { 5566, "DMR, AMMO"},
        { 5514, "DMR, DAMAGE"},
        { 5515, "DMR, POWER"},
        { 5513, "DMR, RATE OF FIRE"},
        { 5501, "SMG"},
        { 5517, "SMG, ACCURACY"},
        { 5518, "SMG, DAMAGE"},
        { 5519, "SMG, POWER"},
        { 5516, "SMG, RATE OF FIRE"},
        { 5500, "BATTLE RIFLE"},
        { 5564, "BATTLE RIFLE, ACCURACY"},
        { 5509, "BATTLE RIFLE, AMMO"},
        { 5510, "BATTLE RIFLE, DAMAGE"},
        { 5511, "BATTLE RIFLE, POWER"},
        { 5565, "BATTLE RIFLE, RANGE"},
        { 5563, "BATTLE RIFLE, RATE OF FIRE"},
        { 5406, "ASSAULT RIFLE"},
        { 5507, "ASSAULT RIFLE, ACCURACY"},
        { 5505, "ASSAULT RIFLE, DAMAGE"},
        { 5508, "ASSAULT RIFLE, POWER"},
        { 5506, "ASSAULT RIFLE, RATE OF FIRE"},
        { 11946, "ACTIVE CAMO"},
        { 11947, "OVERSHIELDS"},
        { 11948, "CUSTOM POWERUP"},
        { 7054, "AMMO CRATE"},
        { 7055, "AMMO CRATE, SMALL"},
        { 428, "FRAG GRENADE"},
        { 431, "PLASMA GRENADE"},
        { 437, "FIREBOMB GRENADE"},
        { 434, "SPIKE GRENADE"},
        { 5483, "CONCUSSIVE BLAST"},
        { 5486, "HOLOGRAM"},
        { 5491, "LIGHTNING STRIKE"},
        { 5487, "REFLECTIVE SHIELD"},
        { 5475, "VEHICLE CAMO"},
        { 5495, "VISION"},
        { 5476, "BUBBLE SHIELD"},
        { 5481, "DEPLOYABLE COVER"},
        { 5477, "FLARE"},
        { 11945, "GRAV LIFT"},
        { 6764, "INVINCIBILITY"},
        { 5473, "POWER DRAIN"},
        { 5472, "RADAR JAMMER"},
        { 5478, "REGENERATOR"},
        { 5479, "TRIP MINE"},
        { 22312, "MAP MODIFIER"},
        { 23174, "PREMATCH CAMERA"},
        { 23182, "KILL VOLUME"},
        { 23183, "GARBAGE COLLECTION VOLUME"},
        { 11979, "GO TO POINT"},
        { 11934, "STARTING POINT"},
        { 11935, "RESPAWN AREA"},
        { 11922, "STARTING POINT"},
        { 11924, "RESPAWN AREA"},
        { 11932, "STARTING POINT"},
        { 11927, "RESPAWN AREA"},
        { 11978, "TERRITORY MARKER"},
        { 11977, "BALL SPAWN POINT"},
        { 11933, "STARTING POINT"},
        { 11980, "RESPAWN AREA"},
        { 11976, "HILL MARKER"},
        { 11930, "STARTING POINT"},
        { 11931, "RESPAWN AREA"},
        { 11975, "GO TO POINT"},
        { 11943, "STARTING POINT"},
        { 11944, "RESPAWN AREA"},
        { 11996, "SAFE HAVEN"},
        { 11925, "RESPAWN, FLAG HOME"},
        { 11926, "RESPAWN, FLAG AWAY"},
        { 11972, "FLAG RETURN POINT"},
        { 11971, "FLAG SPAWN POINT"},
        { 11921, "STARTING POINT"},
        { 11923, "RESPAWN AREA"},
        { 11974, "BOMB PLANT POINT"},
        { 11973, "BOMB SPAWN POINT"},
        { 11928, "STARTING POINT"},
        { 11929, "RESPAWN AREA"},
        { 11920, "RESPAWN POINT"},
        { 186, "HEMISPHERE [1 x 2 x 0.1]"},
        { 187, "HEMISPHERE [1 x 2 x 0.5]"},
        { 188, "HEMISPHERE [1 x 2 x 1]"},
        { 192, "HEMISPHERE [2 x 5 x 0.25]"},
        { 193, "HEMISPHERE [2 x 5 x 1]"},
        { 194, "HEMISPHERE [2 x 5 x 2]"},
        { 198, "HEMISPHERE [5 x 10 x 1]"},
        { 199, "HEMISPHERE [5 x 10 x 2]"},
        { 200, "HEMISPHERE [5 x 10 x 5]"},
        { 204, "HEMISPHERE [10 x 20 x 1]"},
        { 205, "HEMISPHERE [10 x 20 x 5]"},
        { 206, "HEMISPHERE [10 x 20 x 10]"},
        { 185, "HEMISPHERE [2 x 2 x 0.1]"},
        { 184, "HEMISPHERE [2 x 2 x 0.5]"},
        { 207, "HEMISPHERE [2 x 2 x 1]"},
        { 191, "HEMISPHERE [5 x 5 x 0.25]"},
        { 190, "HEMISPHERE [5 x 5 x 1]"},
        { 189, "HEMISPHERE [5 x 5 x 2]"},
        { 197, "HEMISPHERE [10 x 10 x 0.5]"},
        { 196, "HEMISPHERE [10 x 10 x 2]"},
        { 195, "HEMISPHERE [10 x 10 x 5]"},
        { 203, "HEMISPHERE [20 x 20 x 1]"},
        { 202, "HEMISPHERE [20 x 20 x 5]"},
        { 201, "HEMISPHERE [20 x 20 x 10]"},
        { 239, "CYLINDER (HALF) [0.5 x 0.1 x 1]"},
        { 238, "CYLINDER (HALF) [0.5 x 0.1 x 2]"},
        { 240, "CYLINDER (HALF) [0.5 x 0.1 x 3]"},
        { 260, "CYLINDER (HALF) [0.5 x 1 x 1]"},
        { 257, "CYLINDER (HALF) [0.5 x 1 x 2]"},
        { 254, "CYLINDER (HALF) [0.5 x 1 x 3]"},
        { 249, "CYLINDER (HALF) [0.5 x 3 x 1]"},
        { 258, "CYLINDER (HALF) [0.5 x 3 x 2]"},
        { 255, "CYLINDER (HALF) [0.5 x 3 x 3]"},
        { 250, "CYLINDER (HALF) [0.5 x 4 x 1]"},
        { 259, "CYLINDER (HALF) [0.5 x 4 x 2]"},
        { 256, "CYLINDER (HALF) [0.5 x 4 x 3]"},
        { 251, "CYLINDER (HALF) [0.5 x 10 x 1]"},
        { 252, "CYLINDER (HALF) [0.5 x 10 x 2]"},
        { 253, "CYLINDER (HALF) [0.5 x 10 x 3]"},
        { 214, "CYLINDER [0.5 x 0.5 x 0.1]"},
        { 237, "CYLINDER [0.5 x 0.5 x 0.5]"},
        { 221, "CYLINDER [0.5 x 0.5 x 1]"},
        { 224, "CYLINDER [0.5 x 0.5 x 2]"},
        { 227, "CYLINDER [0.5 x 0.5 x 4]"},
        { 215, "CYLINDER [1 x 1 x 0.1]"},
        { 216, "CYLINDER [1 x 1 x 0.5]"},
        { 220, "CYLINDER [1 x 1 x 1]"},
        { 223, "CYLINDER [1 x 1 x 2]"},
        { 226, "CYLINDER [1 x 1 x 4]"},
        { 213, "CYLINDER [2 x 2 x 0.1]"},
        { 217, "CYLINDER [2 x 2 x 0.5]"},
        { 219, "CYLINDER [2 x 2 x 1]"},
        { 222, "CYLINDER [2 x 2 x 2]"},
        { 225, "CYLINDER [2 x 2 x 4]"},
        { 218, "CYLINDER [5 x 5 x 0.1]"},
        { 236, "CYLINDER [5 x 5 x 0.5]"},
        { 235, "CYLINDER [5 x 5 x 1]"},
        { 234, "CYLINDER [5 x 5 x 2]"},
        { 233, "CYLINDER [5 x 5 x 4]"},
        { 232, "CYLINDER [10 x 10 x 0.1]"},
        { 231, "CYLINDER [10 x 10 x 0.5]"},
        { 230, "CYLINDER [10 x 10 x 1]"},
        { 229, "CYLINDER [10 x 10 x 2]"},
        { 228, "CYLINDER [10 x 10 x 4]"},
        { 247, "TRIANGLE (EQUAL) [0.1 x 0.5 x 0.43]"},
        { 245, "TRIANGLE (EQUAL) [0.1 x 1 x 0.87]"},
        { 244, "TRIANGLE (EQUAL) [0.1 x 2 x 1.73]"},
        { 243, "TRIANGLE (EQUAL) [0.1 x 3 x 2.6]"},
        { 242, "TRIANGLE (EQUAL) [0.1 x 4 x 3.46]"},
        { 246, "TRIANGLE (EQUAL) [0.1 x 5 x 4.33]"},
        { 261, "TRIANGLE [1 x 0.5 x 0.5]"},
        { 266, "TRIANGLE [1 x 1 x 1]"},
        { 262, "TRIANGLE [1 x 2 x 2]"},
        { 263, "TRIANGLE [1 x 3 x 3]"},
        { 264, "TRIANGLE [1 x 4 x 4]"},
        { 265, "TRIANGLE [1 x 5 x 5]"},
        { 273, "TRIANGLE [1 x 10 x 10]"},
        { 274, "TRIANGLE [0.5 x 0.5 x 0.5]"},
        { 267, "TRIANGLE [0.5 x 1 x 1]"},
        { 271, "TRIANGLE [0.5 x 2 x 2]"},
        { 270, "TRIANGLE [0.5 x 3 x 3]"},
        { 269, "TRIANGLE [0.5 x 4 x 4]"},
        { 268, "TRIANGLE [0.5 x 5 x 5]"},
        { 272, "TRIANGLE [0.5 x 10 x 10]"},
        { 355, "TRIANGLE [0.1 x 0.5 x 0.5]"},
        { 356, "TRIANGLE [0.1 x 1 x 1]"},
        { 354, "TRIANGLE [0.1 x 2 x 2]"},
        { 353, "TRIANGLE [0.1 x 3 x 3]"},
        { 352, "TRIANGLE [0.1 x 4 x 4]"},
        { 351, "TRIANGLE [0.1 x 5 x 5]"},
        { 350, "TRIANGLE [0.1 x 10 x 10]"},
        { 295, "BLOCK [1 x 20 x 20]"},
        { 290, "BLOCK [1 x 10 x 1]"},
        { 291, "BLOCK [1 x 10 x 2]"},
        { 292, "BLOCK [1 x 10 x 3]"},
        { 293, "BLOCK [1 x 10 x 4]"},
        { 289, "BLOCK [1 x 10 x 5]"},
        { 288, "BLOCK [1 x 10 x 10]"},
        { 284, "BLOCK [1 x 5 x 1]"},
        { 280, "BLOCK [1 x 5 x 2]"},
        { 281, "BLOCK [1 x 5 x 3]"},
        { 282, "BLOCK [1 x 5 x 4]"},
        { 279, "BLOCK [1 x 5 x 5]"},
        { 286, "BLOCK [1 x 4 x 1]"},
        { 294, "BLOCK [1 x 4 x 2]"},
        { 277, "BLOCK [1 x 4 x 3]"},
        { 278, "BLOCK [1 x 4 x 4]"},
        { 285, "BLOCK [1 x 3 x 1]"},
        { 275, "BLOCK [1 x 3 x 2]"},
        { 276, "BLOCK [1 x 3 x 3]"},
        { 283, "BLOCK [1 x 2 x 1]"},
        { 320, "BLOCK [1 x 2 x 2]"},
        { 287, "BLOCK [1 x 1 x 1]"},
        { 296, "BLOCK [0.5 x 20 x 20]"},
        { 303, "BLOCK [0.5 x 10 x 1]"},
        { 302, "BLOCK [0.5 x 10 x 2]"},
        { 301, "BLOCK [0.5 x 10 x 3]"},
        { 300, "BLOCK [0.5 x 10 x 4]"},
        { 304, "BLOCK [0.5 x 10 x 5]"},
        { 305, "BLOCK [0.5 x 10 x 10]"},
        { 309, "BLOCK [0.5 x 5 x 1]"},
        { 313, "BLOCK [0.5 x 5 x 2]"},
        { 312, "BLOCK [0.5 x 5 x 3]"},
        { 311, "BLOCK [0.5 x 5 x 4]"},
        { 314, "BLOCK [0.5 x 5 x 5]"},
        { 307, "BLOCK [0.5 x 4 x 1]"},
        { 297, "BLOCK [0.5 x 4 x 2]"},
        { 316, "BLOCK [0.5 x 4 x 3]"},
        { 315, "BLOCK [0.5 x 4 x 4]"},
        { 308, "BLOCK [0.5 x 3 x 1]"},
        { 318, "BLOCK [0.5 x 3 x 2]"},
        { 317, "BLOCK [0.5 x 3 x 3]"},
        { 310, "BLOCK [0.5 x 2 x 1]"},
        { 319, "BLOCK [0.5 x 2 x 2]"},
        { 299, "BLOCK [0.5 x 1 x 0.5]"},
        { 306, "BLOCK [0.5 x 1 x 1]"},
        { 298, "BLOCK [0.5 x 0.5 x 0.5]"},
        { 349, "BLOCK [0.1 x 20 x 20]"},
        { 343, "BLOCK [0.1 x 10 x 0.5]"},
        { 325, "BLOCK [0.1 x 10 x 1]"},
        { 324, "BLOCK [0.1 x 10 x 2]"},
        { 323, "BLOCK [0.1 x 10 x 3]"},
        { 322, "BLOCK [0.1 x 10 x 4]"},
        { 326, "BLOCK [0.1 x 10 x 5]"},
        { 327, "BLOCK [0.1 x 10 x 10]"},
        { 347, "BLOCK [0.1 x 5 x 0.5]"},
        { 331, "BLOCK [0.1 x 5 x 1]"},
        { 335, "BLOCK [0.1 x 5 x 2]"},
        { 334, "BLOCK [0.1 x 5 x 3]"},
        { 333, "BLOCK [0.1 x 5 x 4]"},
        { 336, "BLOCK [0.1 x 5 x 5]"},
        { 345, "BLOCK [0.1 x 4 x 0.5]"},
        { 329, "BLOCK [0.1 x 4 x 1]"},
        { 321, "BLOCK [0.1 x 4 x 2]"},
        { 338, "BLOCK [0.1 x 4 x 3]"},
        { 337, "BLOCK [0.1 x 4 x 4]"},
        { 346, "BLOCK [0.1 x 3 x 0.5]"},
        { 330, "BLOCK [0.1 x 3 x 1]"},
        { 340, "BLOCK [0.1 x 3 x 2]"},
        { 339, "BLOCK [0.1 x 3 x 3]"},
        { 342, "BLOCK [0.1 x 2 x 0.5]"},
        { 332, "BLOCK [0.1 x 2 x 1]"},
        { 341, "BLOCK [0.1 x 2 x 2]"},
        { 344, "BLOCK [0.1 x 1 x 0.5]"},
        { 328, "BLOCK [0.1 x 1 x 1]"},
        { 348, "BLOCK [0.1 x 0.5 x 0.5]"},
        { 11952, "BACKPACK"},
        { 21990, "BEACON"},
        { 13506, "BLITZ CAN"},
        { 20000, "BRIDGE"},
        { 11954, "CAMPING STOOL"},
        { 21666, "CHAIN LINK GATE"},
        { 22281, "CROWBAR"},
        { 20935, "DROP BRIDGE"},
        { 13480, "DROP POD, CLOSED"},
        { 13454, "DROP POD, DEPLOYED"},
        { 13481, "DROP POD, PANEL"},
        { 21653, "FLOOR HATCH"},
        { 20878, "GARBAGE CAN"},
        { 18405, "LOCKER"},
        { 18110, "LOUDSPEAKER"},
        { 21532, "MEDICAL CABINET"},
        { 21578, "MEDICAL CART"},
        { 21600, "MEDICAL TRAY"},
        { 18505, "MISSILE, BODY"},
        { 18018, "MISSILE, STACK"},
        { 18510, "MISSILE, WARHEAD"},
        { 13459, "MONGOOSE PLATFORM"},
        { 16930, "PALLET"},
        { 11959, "PALLET, LARGE"},
        { 22011, "PHANTOM DESTROYED, BACK, LARGE"},
        { 22016, "PHANTOM DESTROYED, BACK, MEDIUM"},
        { 22021, "PHANTOM DESTROYED, BACK, SMALL"},
        { 22026, "PHANTOM DESTROYED, BOTTOM"},
        { 22036, "PHANTOM DESTROYED, FLAT, RIGHT"},
        { 22046, "PHANTOM DESTROYED, SIDE, LEFT"},
        { 22051, "PHANTOM DESTROYED, SIDE, RIGHT"},
        { 13477, "RADIO ANTENNAE"},
        { 11961, "STREET CONE"},
        { 16931, "SWINGING DOOR"},
        { 20989, "SWINGING LAMP"},
        { 18533, "TOOLBOX"},
        { 18515, "TOOLBOX, SMALL"},
        { 16934, "TRASH CAN"},
        { 13458, "WARTHOG PLATFORM"},
        { 10870, "WARTHOG TIRE"},
        { 18093, "WEAPON SHELF"},
        { 19976, "WIRE SPOOL"},
        { 18740, "CHAIR"},
        { 18712, "COMPUTER MONITOR"},
        { 18723, "FILING CABINET"},
        { 18735, "FILING CABINET, SMALL"},
        { 18702, "KEYBOARD"},
        { 18084, "KITCHEN SINK"},
        { 21713, "STAND"},
        { 17928, "TABLE"},
        { 21611, "TELEPHONE"},
        { 18671, "TELEPHONE, WALL"},
        { 20056, "SOCCER BALL"},
        { 11966, "WEAPON HOLDER"},
        { 11967, "GRAV LIFT"},
        { 23253, "LIFT, GOLD"},
        { 20038, "MAN CANNON"},
        { 20033, "SHIELD DOOR"},
        { 14996, "SHIELD DOOR 2"},
        { 20011, "SHIELD DOOR, LARGE"},
        { 12005, "SHIELD DOOR, GOLD"},
        { 21543, "COMPUTER"},
        { 21569, "COMPUTER, SMALL"},
        { 18363, "FLOODLIGHTS"},
        { 18789, "FORKLIFT"},
        { 18381, "GENERATOR"},
        { 18749, "GENERATOR, INDUSTRIAL"},
        { 11965, "GENERATOR, SMALL"},
        { 17482, "INDUSTRIAL CART"},
        { 18054, "MONITOR, MEDIUM"},
        { 18079, "MONITOR, SMALL"},
        { 11951, "RADIO SET"},
        { 13479, "RADIO SET, SMALL"},
        { 176, "YELLOW"},
        { 176, "ORANGE"},
        { 176, "PINK"},
        { 176, "RED"},
        { 176, "PURPLE"},
        { 176, "BLUE"},
        { 176, "GREEN"},
        { 180, "JUICY"},
        { 180, "NOVA"},
        { 180, "SEPIATONE"},
        { 180, "FILM"},
        { 180, "GLOOMY"},
        { 23144, "TRIP MINE (ARMED)"},
        { 11962, "PLASMA BATTERY"},
        { 13476, "FUSION COIL"},
        { 11963, "POWER CORE"},
        { 19370, "PROPANE BURNER"},
        { 18541, "PROPANE TANK"},
        { 18353, "AMMO CASE"},
        { 16342, "AMMO CRATE"},
        { 16341, "AMMO CRATE, SMALL"},
        { 16932, "CABINET"},
        { 20858, "CONTAINER"},
        { 20873, "CONTAINER, OPEN"},
        { 10223, "CRATE, INDUSTRIAL"},
        { 17484, "CRATE, MULTI"},
        { 16929, "CRATE, MULTI, DESTRUCTIBLE"},
        { 11955, "CRATE, SINGLE"},
        { 11956, "CRATE, SINGLE, LARGE"},
        { 19984, "DOUBLE BOX, OPEN"},
        { 11964, "EQUIPMENT CASE"},
        { 20208, "EQUIPMENT CASE, LID"},
        { 20195, "EQUIPMENT CASE, OPEN"},
        { 13478, "EQUIPMENT CASE, SMALL"},
        { 19951, "FENCE BOX"},
        { 13483, "MEDICAL CRATE"},
        { 16339, "METAL CRATE"},
        { 16928, "METAL CRATE, SMALL"},
        { 13504, "SUPPLY CASE"},
        { 20970, "AWNING"},
        { 13482, "BARRICADE"},
        { 16340, "BARRICADE, SMALL"},
        { 18418, "BARRIER"},
        { 18458, "BARRIER, SHORT"},
        { 21008, "BATTLE SHIELD"},
        { 16933, "DUMPSTER"},
        { 11960, "ROADBLOCK"},
        { 23171, "ROADBLOCK, LIGHT"},
        { 20723, "SANDBAGS"},
        { 19791, "SANDBAGS, 45 CORNER"},
        { 20713, "SANDBAGS, 90 CORNER"},
        { 20718, "SANDBAGS, ENDCAP"},
        { 19734, "SANDBAGS, TURRET"},
        { 20733, "SANDBAG, SINGLE"},
        { 20728, "SANDBAG, TWO"},
        { 20228, "BUSH, A"},
        { 20233, "BUSH, B"},
        { 20213, "BUSH, SMALL"},
        { 14868, "ICICLE, 10 INCH"},
        { 14869, "ICICLE, 18 INCH"},
        { 19278, "ICICLE, 24 INCH"},
        { 16873, "ICICLE, 6 INCH"},
        { 21034, "PALM BUSH, LARGE"},
        { 21018, "PALM BUSH, MEDIUM"},
        { 21029, "PALM TREE, SMALL"},
        { 13507, "PINE TREE"},
        { 13509, "PINE TREE, LARGE"},
        { 11957, "BARREL"},
        { 11958, "BARREL, SMALL"},
        { 13505, "DRUM, 12 GAL"},
        { 19960, "DRUM, 55 GAL"}
};

#endif