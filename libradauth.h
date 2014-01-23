#ifndef _LIBRADAUTH_H
#define _LIBRADAUTH_H

/* Indicates from where the callback function was called */
typedef enum {
	RAD_CB_VALUEPAIRS = 0, /* data: (VALUE_PAIR *) */
} rad_cb_action;

void rad_auth_init(const char *userdict);
int rad_auth_simple(const char *username, const char *password,
		const char *config);
int rad_auth(const char *username, const char *password,
		int tries, const char *config, const char *userdict,
		const char *vps);
int rad_auth_r(const char *username, const char *password,
		int tries, const char *config, const char *vps,
		char *errmsg);
int rad_auth_cb(const char *username, const char *password,
		int tries, const char *config, const char *userdict,
		int(*cb)(rad_cb_action, const void *, void *),
		const void *arg);
int rad_auth_cb_r(const char *username, const char *password,
		int tries, const char *config,
		int(*cb)(rad_cb_action, const void *, void *),
		const void *arg, char *errmsg);
char *rad_auth_errstr(void);

#endif
