//
//  serverdef.h
//  
//
//  Created by gyf on 12-4-9.
//  Copyright (c) 2012年 G4 Workshop. All rights reserved.
//

#ifndef Comm_serverdef_h
#define Comm_serverdef_h


#define G4_COMM_PLAYER_LOGIN        0x01
#define G4_COMM_NPC_LOGIN           0x02
#define G4_COMM_PLAYER_LOGOUT       0x03
#define G4_COMM_PLAYER_LEAVE        0x05


#define G4_COMM_PLAYER_LEAVED       0x07    
#define G4_COMM_MATCH_DISMISSED     0x08
#define G4_COMM_MATCH_CREATED       0x09
#define G4_COMM_PLAYER_MATCHED      0x06    //一个用户加入到match
#define G4_COMM_MATCH_REQUEST       0x04

#define G4_COMM_CONNECTED           0xf0
#define G4_COMM_DISCONNECTED        0xf1

#define G4_COMM_HELLO               0xff

#define G4_KEY_PLAYER_ID            0x01
#define G4_KEY_PLAYER_NAME          0x02
#define G4_KEY_MATCH_ID             0x03
#define G4_KEY_PASSWORD             0x04
#define G4_KEY_MIN_PLAYER           0x05
#define G4_KEY_MAX_PLAYER           0x06
#define G4_KEY_PARAMETER            0x07
#define G4_KEY_MODE                 0x08
#define G4_KEY_MATCH_NAME           0x09
#define G4_KEY_RANDOMID             0x0a


#define G4_ERR_NO_RESULT            0xff  //此结果无效
#define G4_ERR_TIME_OUT             0xfe
#define G4_ERR_USER_CANCELLED       0x01

#define PAIR_MESSAGE_ID_GAMEDATA (0x1001)
#define PAIR_MESSAGE_ID_RESIGN   (0x1002)
#define PAIR_MESSAGE_ID_TIMEOUT  (0x1003)
#define PAIR_MESSAGE_ID_DEMON  (0x1004)
#define PAIR_MESSAGE_ID_SERIAL (0x1005)
#define PAIR_MESSAGE_ID_CELL_ARRAY (0x1006)
#define PAIR_MESSAGE_ID_CELL_ARRAY_ACK (0x1007)
#define PAIR_MESSAGE_ID_COMBO (0x1008)
#define PAIR_MESSAGE_ID_COIN (0x1009)
#define PAIR_MESSAGE_ID_CROW (0x100A)

#define PAIR_KEY_SCORE (0x1001)
#define PAIR_KEY_REMAINTIME (0x1002)
#define PAIR_KEY_HINT (0x1003)
#define PAIR_KEY_BOMB (0x1004)
#define PAIR_KEY_DEMON (0x1005)
#define PAIR_KEY_SERIAL (0x1006)
#define PAIR_KEY_CAPABILITY (0x1007)
#define PAIR_KEY_DATA (0x1008)
#define PAIR_KEY_BONUS (0x1009)

#endif
