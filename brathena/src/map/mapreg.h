/****************************************************************************!
*                _           _   _   _                                       *    
*               | |__  _ __ / \ | |_| |__   ___ _ __   __ _                  *  
*               | '_ \| '__/ _ \| __| '_ \ / _ \ '_ \ / _` |                 *   
*               | |_) | | / ___ \ |_| | | |  __/ | | | (_| |                 *    
*               |_.__/|_|/_/   \_\__|_| |_|\___|_| |_|\__,_|                 *    
*                                                                            *
*                                                                            *
* \file src/map/mapreg.h                                                     *
* Descri��o Prim�ria.                                                        *
* Descri��o mais elaborada sobre o arquivo.                                  *
* \author brAthena, Athena, eAthena                                          *
* \date ?                                                                    *
* \todo ?                                                                    *  
*****************************************************************************/

#ifndef _MAPREG_H_
#define _MAPREG_H_

#include "../common/cbasetypes.h"
#include "../common/db.h"

struct mapreg_save {
	int uid;
	union {
		int i;
		char *str;
	} u;
	bool save;
};

struct mapreg_interface {
	DBMap *db; // int var_id -> int value
	DBMap *str_db; // int var_id -> char* value
	struct eri *ers; //[Ind/Hercules]
	char table[32];
	bool i_dirty;
	bool str_dirty;
	/* */
	void (*init) (void);
	void (*final) (void);
	/* */
	int (*readreg) (int uid);
	char* (*readregstr) (int uid);
	bool (*setreg) (int uid, int val);
	bool (*setregstr) (int uid, const char *str);
	void (*load) (void);
	void (*save) (void);
	int (*save_timer) (int tid, int64 tick, int id, intptr_t data);
	void (*reload) (void);
	bool (*config_read) (const char *w1, const char *w2);
};

struct mapreg_interface *mapreg;

void mapreg_defaults(void);

#endif /* _MAPREG_H_ */
