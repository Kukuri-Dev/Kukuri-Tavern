#pragma once

enum eTileSpread {
    TILESPREAD_NONE,
    TILESPREAD_SINGLE,
    TILESPREAD_DIRECT8,
    TILESPREAD_HORIZONTAL,
    TILESPREAD_ATTACH_TO_WALL_5,
    TILESPREAD_DIRECT4,
    TILESPREAD_RANDOM,
    TILESPREAD_VERTICAL,
    TILESPREAD_CAVE_PLAT,
    TILESPREAD_ATTACH_TO_WALL_4,
    TILESPREAD_DIAGONAL
};

enum eClothTypes {
    CLOTHTYPE_HAIR,
    CLOTHTYPE_SHIRT,
    CLOTHTYPE_PANTS,
    CLOTHTYPE_FEET,
    CLOTHTYPE_FACE,
    CLOTHTYPE_HAND,
    CLOTHTYPE_BACK,
    CLOTHTYPE_MASK,
    CLOTHTYPE_NECKLACE,
    CLOTHTYPE_ANCES,
    NUM_BODY_PARTS
};

enum eItemTypes {
    ITEMTYPE_FIST = 0,
    ITEMTYPE_WRENCH = 1,
    ITEMTYPE_DOOR = 2,
    ITEMTYPE_LOCK = 3,
    ITEMTYPE_GEMS = 4,
    ITEMTYPE_TREASURE = 5,
    ITEMTYPE_DEADLY_BLOCK = 6,
    ITEMTYPE_TRAMPOLINE = 7,
    ITEMTYPE_CONSUMABLE = 8,
    ITEMTYPE_GATEWAY = 9,
    ITEMTYPE_SIGN = 10,
    ITEMTYPE_SFX_WITH_EXTRA_FRAME = 11,
    ITEMTYPE_BOOMBOX = 12,
    ITEMTYPE_MAIN_DOOR = 13,
    ITEMTYPE_PLATFORM = 14,
    ITEMTYPE_BEDROCK = 15,
    ITEMTYPE_LAVA = 16,
    ITEMTYPE_FOREGROUND = 17,
    ITEMTYPE_BACKGROUND = 18,
    ITEMTYPE_SEED = 19,
    ITEMTYPE_CLOTHES = 20,
    ITEMTYPE_FOREGROUND_WITH_EXTRA_FRAME = 21,
    ITEMTYPE_BACKGD_SFX_EXTRA_FRAME = 22,
    ITEMTYPE_BACK_BOOMBOX = 23,
    ITEMTYPE_BOUNCY = 24,
    ITEMTYPE_POINTY = 25,
    ITEMTYPE_PORTAL = 26,
    ITEMTYPE_CHECKPOINT = 27,
    ITEMTYPE_MUSIC_NOTE = 28,
    ITEMTYPE_ICE = 29,
    ITEMTYPE_SWITCHEROO = 31,
    ITEMTYPE_CHEST = 32,
    ITEMTYPE_MAILBOX = 33,
    ITEMTYPE_BULLETIN = 34,
    ITEMTYPE_PINATA = 35,
    ITEMTYPE_DICE = 36,
    ITEMTYPE_CHEMICAL = 37,
    ITEMTYPE_PROVIDER = 38,
    ITEMTYPE_LAB = 39,
    ITEMTYPE_ACHIEVEMENT = 40,
    ITEMTYPE_WEATHER_MACHINE = 41,
    ITEMTYPE_SCORE_BOARD = 42,
    ITEMTYPE_SUNGATE = 43,
    ITEMTYPE_PROFILE = 44,
    ITEMTYPE_DEADLY_IF_ON = 45,
    ITEMTYPE_HEART_MONITOR = 46,
    ITEMTYPE_DONATION_BOX = 47,
    ITEMTYPE_TOYBOX = 48,
    ITEMTYPE_MANNEQUIN = 49,
    ITEMTYPE_SECURITY_CAMERA = 50,
    ITEMTYPE_MAGIC_EGG = 51,
    ITEMTYPE_GAME_RESOURCES = 52,
    ITEMTYPE_GAME_GENERATOR = 53,
    ITEMTYPE_XENONITE = 54,
    ITEMTYPE_DRESSUP = 55,
    ITEMTYPE_CRYSTAL = 56,
    ITEMTYPE_BURGLAR = 57,
    ITEMTYPE_COMPACTOR = 58,
    ITEMTYPE_SPOTLIGHT = 59,
    ITEMTYPE_WIND = 60,
    ITEMTYPE_DISPLAY_BLOCK = 61,
    ITEMTYPE_VENDING_MACHINE = 62,
    ITEMTYPE_FISHTANK = 63,
    ITEMTYPE_PETFISH = 64,
    ITEMTYPE_SOLAR = 65,
    ITEMTYPE_FORGE = 66,
    ITEMTYPE_GIVING_TREE = 67,
    ITEMTYPE_GIVING_TREE_STUMP = 68,
    ITEMTYPE_STEAMPUNK = 69,
    ITEMTYPE_STEAM_LAVA_IF_ON = 70,
    ITEMTYPE_STEAM_ORGAN = 71,
    ITEMTYPE_TAMAGOTCHI = 72,
    ITEMTYPE_SWING = 73,
    ITEMTYPE_FLAG = 74,
    ITEMTYPE_LOBSTER_TRAP = 75,
    ITEMTYPE_ART_CANVAS = 76,
    ITEMTYPE_BATTLE_CAGE = 77,
    ITEMTYPE_PET_TRAINER = 78,
    ITEMTYPE_STEAM_ENGINE = 79,
    ITEMTYPE_LOCKBOT = 80,
    ITEMTYPE_WEATHER_SPECIAL = 81,
    ITEMTYPE_SPIRIT_STORAGE = 82,
    ITEMTYPE_DISPLAY_SHELF = 83,
    ITEMTYPE_VIP_ENTRANCE = 84,
    ITEMTYPE_CHALLENGE_TIMER = 85,
    ITEMTYPE_CHALLENGE_FLAG = 86,
    ITEMTYPE_FISH_MOUNT = 87,
    ITEMTYPE_PORTRAIT = 88,
    ITEMTYPE_WEATHER_SPECIAL2 = 89,
    ITEMTYPE_FOSSIL = 90,
    ITEMTYPE_FOSSIL_PREP = 91,
    ITEMTYPE_DNA_MACHINE = 92,
    ITEMTYPE_BLASTER = 93,
    ITEMTYPE_VALHOWLA = 94,
    ITEMTYPE_CHEMSYNTH = 95,
    ITEMTYPE_CHEMTANK = 96,
    ITEMTYPE_STORAGE = 97,
    ITEMTYPE_OVEN = 98,
    ITEMTYPE_SUPER_MUSIC = 99,
    ITEMTYPE_GEIGER_CHARGER = 100,
    ITEMTYPE_ADVENTURE_RESET = 101,
    ITEMTYPE_TOMB_ROBBER = 102,
    ITEMTYPE_FACTION = 103,
    ITEMTYPE_RED_FACTION = 104,
    ITEMTYPE_GREEN_FACTION = 105,
    ITEMTYPE_BLUE_FACTION = 106,
    ITEMTYPE_ANCES = 107,
    ITEMTYPE_FISHGOTCHI_TANK = 109,
    ITEMTYPE_FISHING_BLOCK = 110,
    ITEMTYPE_ITEM_SUCKER = 111,
    ITEMTYPE_ITEM_PLANTER = 112,
    ITEMTYPE_ROBOT = 113,
    ITEMTYPE_COMMAND = 114,
    ITEMTYPE_TICKET = 115,
    ITEMTYPE_STATS_BLOCK = 116,
    ITEMTYPE_FIELD_NODE = 117,
    ITEMTYPE_OUIJA_BOARD = 118,
    ITEMTYPE_ARCHITECT_MACHINE = 119,
    ITEMTYPE_STARSHIP = 120,
    ITEMTYPE_AUTODELETE = 121,
    ITEMTYPE_GREEN_FOUNTAIN = 122,
    ITEMTYPE_AUTO_ACTION_BREAK = 123,
    ITEMTYPE_AUTO_ACTION_HARVEST = 124,
    ITEMTYPE_AUTO_ACTION_HARVEST_SUCK = 125,
    ITEMTYPE_LIGHTNING_IF_ON = 126,
    ITEMTYPE_PHASED_BLOCK = 127,
    ITEMTYPE_MUD = 128,
    ITEMTYPE_ROOT_CUTTING = 129,
    ITEMTYPE_PASSWORD_STORAGE = 130,
    ITEMTYPE_PHASED_BLOCK_2 = 131,
    ITEMTYPE_BOMB = 132,
    ITEMTYPE_WEATHER_INFINITY = 134,
    ITEMTYPE_SLIME = 135,
    ITEMTYPE_UNK1 = 136,
    ITEMTYPE_COMPLETIONIST = 137,
    ITEMTYPE_SWITCHEROO2 = 138,
    ITEMTYPE_FEEDING_BLOCK = 140,
    ITEMTYPE_KRANKENS_BLOCK = 141,
    ITEMTYPE_FRIENDS_ENTRANCE = 142
};