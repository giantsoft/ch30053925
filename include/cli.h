// Author:			William Joseph Oney, Jr.
// Contact:			giantsoftllc@gmail.com
// Organization:
// Date:			2016

#ifndef CH30053925_CLI_H
#define CH30053925_CLI_H

typedef struct command_type {

	void * proc_func;
	char * str

};

typedef struct cmd_set {


	cmd_type cmd;

};

const size_t sz_cmd_type = sizeof( command_type );

cli_add_cmd( id, ) {

}

cli_proc_cmds( const cmd_type * cmds, const int argc, const char * argv[] ) {

	printf()

}

#endif