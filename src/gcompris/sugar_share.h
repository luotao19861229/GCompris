/* sugar_share.h generated by valac, the Vala compiler, do not modify */


#ifndef __SUGAR_SHARE_H__
#define __SUGAR_SHARE_H__

#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <glib-object.h>

G_BEGIN_DECLS


#define TYPE_ADMINISTRATION (administration_get_type ())
#define ADMINISTRATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ADMINISTRATION, Administration))
#define ADMINISTRATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ADMINISTRATION, AdministrationClass))
#define IS_ADMINISTRATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ADMINISTRATION))
#define IS_ADMINISTRATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ADMINISTRATION))
#define ADMINISTRATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ADMINISTRATION, AdministrationClass))

typedef struct _Administration Administration;
typedef struct _AdministrationClass AdministrationClass;
typedef struct _AdministrationPrivate AdministrationPrivate;

#define TYPE_ADMINISTRATION_CLIENT (administration_client_get_type ())
#define ADMINISTRATION_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ADMINISTRATION_CLIENT, AdministrationClient))
#define ADMINISTRATION_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ADMINISTRATION_CLIENT, AdministrationClientClass))
#define IS_ADMINISTRATION_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ADMINISTRATION_CLIENT))
#define IS_ADMINISTRATION_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ADMINISTRATION_CLIENT))
#define ADMINISTRATION_CLIENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ADMINISTRATION_CLIENT, AdministrationClientClass))

typedef struct _AdministrationClient AdministrationClient;
typedef struct _AdministrationClientClass AdministrationClientClass;
typedef struct _AdministrationClientPrivate AdministrationClientPrivate;

#define TYPE_ADMINISTRATION_SERVER (administration_server_get_type ())
#define ADMINISTRATION_SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ADMINISTRATION_SERVER, AdministrationServer))
#define ADMINISTRATION_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ADMINISTRATION_SERVER, AdministrationServerClass))
#define IS_ADMINISTRATION_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ADMINISTRATION_SERVER))
#define IS_ADMINISTRATION_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ADMINISTRATION_SERVER))
#define ADMINISTRATION_SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ADMINISTRATION_SERVER, AdministrationServerClass))

typedef struct _AdministrationServer AdministrationServer;
typedef struct _AdministrationServerClass AdministrationServerClass;
typedef struct _AdministrationServerPrivate AdministrationServerPrivate;

typedef char* (*GetProfileCallback) (void* user_data);
typedef void (*ReportCallback) (const char* date, gint duration, const char* user, const char* board, gint level, gint sublevel, gint status, const char* comment, void* user_data);
typedef void (*GotProfileCallback) (const char* data, void* user_data);
struct _Administration {
	GObject parent_instance;
	AdministrationPrivate * priv;
};

struct _AdministrationClass {
	GObjectClass parent_class;
};

struct _AdministrationClient {
	GTypeInstance parent_instance;
	volatile int ref_count;
	AdministrationClientPrivate * priv;
};

struct _AdministrationClientClass {
	GTypeClass parent_class;
	void (*finalize) (AdministrationClient *self);
};

struct _AdministrationServer {
	GTypeInstance parent_instance;
	volatile int ref_count;
	AdministrationServerPrivate * priv;
};

struct _AdministrationServerClass {
	GTypeClass parent_class;
	void (*finalize) (AdministrationServer *self);
};


GType administration_get_type (void);
Administration* administration_new (GetProfileCallback GetProfile_cb, void* GetProfile_cb_target, ReportCallback Report_cb, void* Report_cb_target);
Administration* administration_construct (GType object_type, GetProfileCallback GetProfile_cb, void* GetProfile_cb_target, ReportCallback Report_cb, void* Report_cb_target);
char* administration_GetProfile (Administration* self);
void administration_Report (Administration* self, const char* date, gint duration, const char* user, const char* board, gint level, gint sublevel, gint status, const char* comment);
gpointer administration_client_ref (gpointer instance);
void administration_client_unref (gpointer instance);
GParamSpec* param_spec_administration_client (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_administration_client (GValue* value, gpointer v_object);
void value_take_administration_client (GValue* value, gpointer v_object);
gpointer value_get_administration_client (const GValue* value);
GType administration_client_get_type (void);
AdministrationClient* administration_client_new (const char* address, const char* name, GotProfileCallback GotProfile_cb, void* GotProfile_cb_target);
AdministrationClient* administration_client_construct (GType object_type, const char* address, const char* name, GotProfileCallback GotProfile_cb, void* GotProfile_cb_target);
void administration_client_import_profile (AdministrationClient* self);
void administration_client_report (AdministrationClient* self, const char* date, gint duration, const char* user, const char* board, gint level, gint sublevel, gint status, const char* comment);
gpointer administration_server_ref (gpointer instance);
void administration_server_unref (gpointer instance);
GParamSpec* param_spec_administration_server (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_administration_server (GValue* value, gpointer v_object);
void value_take_administration_server (GValue* value, gpointer v_object);
gpointer value_get_administration_server (const GValue* value);
GType administration_server_get_type (void);
AdministrationServer* administration_server_new (const char* address, GetProfileCallback GetProfile_cb, void* GetProfile_cb_target, ReportCallback Report_cb, void* Report_cb_target);
AdministrationServer* administration_server_construct (GType object_type, const char* address, GetProfileCallback GetProfile_cb, void* GetProfile_cb_target, ReportCallback Report_cb, void* Report_cb_target);
void administration_server_update_profile (AdministrationServer* self);


G_END_DECLS

#endif