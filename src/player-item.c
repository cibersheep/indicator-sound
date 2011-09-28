/* player-item.c generated by valac 0.14.0, the Vala compiler
 * generated from player-item.vala, do not modify */

/*
Copyright 2010 Canonical Ltd.

Authors:
    Conor Curran <conor.curran@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License version 3, as published 
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <glib.h>
#include <glib-object.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/dbusmenu-glib.h>
#include <libdbusmenu-glib/enum-types.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <libdbusmenu-glib/types.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define TYPE_PLAYER_ITEM (player_item_get_type ())
#define PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_ITEM, PlayerItem))
#define PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_ITEM, PlayerItemClass))
#define IS_PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_ITEM))
#define IS_PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_ITEM))
#define PLAYER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_ITEM, PlayerItemClass))

typedef struct _PlayerItem PlayerItem;
typedef struct _PlayerItemClass PlayerItemClass;
typedef struct _PlayerItemPrivate PlayerItemPrivate;

#define TYPE_PLAYER_CONTROLLER (player_controller_get_type ())
#define PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_CONTROLLER, PlayerController))
#define PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))
#define IS_PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_CONTROLLER))
#define IS_PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_CONTROLLER))
#define PLAYER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))

typedef struct _PlayerController PlayerController;
typedef struct _PlayerControllerClass PlayerControllerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_variant_unref0(var) ((var == NULL) ? NULL : (var = (g_variant_unref (var), NULL)))

#define TYPE_METADATA_MENUITEM (metadata_menuitem_get_type ())
#define METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitem))
#define METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))
#define IS_METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_METADATA_MENUITEM))
#define IS_METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_METADATA_MENUITEM))
#define METADATA_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))

typedef struct _MetadataMenuitem MetadataMenuitem;
typedef struct _MetadataMenuitemClass MetadataMenuitemClass;

struct _PlayerItem {
	DbusmenuMenuitem parent_instance;
	PlayerItemPrivate * priv;
};

struct _PlayerItemClass {
	DbusmenuMenuitemClass parent_class;
};

struct _PlayerItemPrivate {
	PlayerController* _owner;
	gchar* _item_type;
};


static gpointer player_item_parent_class = NULL;

GType player_item_get_type (void) G_GNUC_CONST;
GType player_controller_get_type (void) G_GNUC_CONST;
#define PLAYER_ITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PLAYER_ITEM, PlayerItemPrivate))
enum  {
	PLAYER_ITEM_DUMMY_PROPERTY,
	PLAYER_ITEM_OWNER,
	PLAYER_ITEM_ITEM_TYPE
};
#define PLAYER_ITEM_EMPTY (-1)
PlayerItem* player_item_new (const gchar* type);
PlayerItem* player_item_construct (GType object_type, const gchar* type);
void player_item_reset (PlayerItem* self, GeeHashSet* attrs);
void player_item_update (PlayerItem* self, GHashTable* data, GeeHashSet* attributes);
GType metadata_menuitem_get_type (void) G_GNUC_CONST;
void metadata_menuitem_fetch_art (MetadataMenuitem* self, const gchar* uri, const gchar* prop);
gboolean player_item_populated (PlayerItem* self, GeeHashSet* attrs);
PlayerController* player_item_get_owner (PlayerItem* self);
static void player_item_set_owner (PlayerItem* self, PlayerController* value);
const gchar* player_item_get_item_type (PlayerItem* self);
static void player_item_set_item_type (PlayerItem* self, const gchar* value);
static GObject * player_item_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void player_item_finalize (GObject* obj);
static void _vala_player_item_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_player_item_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


PlayerItem* player_item_construct (GType object_type, const gchar* type) {
	PlayerItem * self = NULL;
	const gchar* _tmp0_;
	g_return_val_if_fail (type != NULL, NULL);
	_tmp0_ = type;
	self = (PlayerItem*) g_object_new (object_type, "item-type", _tmp0_, NULL);
	return self;
}


PlayerItem* player_item_new (const gchar* type) {
	return player_item_construct (TYPE_PLAYER_ITEM, type);
}


void player_item_reset (PlayerItem* self, GeeHashSet* attrs) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (attrs != NULL);
	{
		GeeHashSet* _tmp0_;
		GeeIterator* _tmp1_ = NULL;
		GeeIterator* _s_it;
		_tmp0_ = attrs;
		_tmp1_ = gee_abstract_collection_iterator ((GeeAbstractCollection*) _tmp0_);
		_s_it = _tmp1_;
		while (TRUE) {
			GeeIterator* _tmp2_;
			gboolean _tmp3_ = FALSE;
			GeeIterator* _tmp4_;
			gpointer _tmp5_ = NULL;
			gchar* s;
			const gchar* _tmp6_;
			_tmp2_ = _s_it;
			_tmp3_ = gee_iterator_next (_tmp2_);
			if (!_tmp3_) {
				break;
			}
			_tmp4_ = _s_it;
			_tmp5_ = gee_iterator_get (_tmp4_);
			s = (gchar*) _tmp5_;
			_tmp6_ = s;
			dbusmenu_menuitem_property_set_int ((DbusmenuMenuitem*) self, _tmp6_, PLAYER_ITEM_EMPTY);
			_g_free0 (s);
		}
		_g_object_unref0 (_s_it);
	}
}


/**
   * update()
   * Base update method for playeritems, takes the attributes and the incoming updates
   * and attmepts to update the appropriate props on the object. 
   * Album art is handled separately to deal with remote and local file paths.
   */
static gpointer _g_variant_ref0 (gpointer self) {
	return self ? g_variant_ref (self) : NULL;
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _result_;
	const gchar* _tmp1_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = needle;
	_tmp1_ = strstr ((gchar*) self, (gchar*) _tmp0_);
	result = _tmp1_ != NULL;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void player_item_update (PlayerItem* self, GHashTable* data, GeeHashSet* attributes) {
	GHashTable* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (data != NULL);
	g_return_if_fail (attributes != NULL);
	_tmp0_ = data;
	if (_tmp0_ == NULL) {
		g_warning ("player-item.vala:54: PlayerItem::Update -> The hashtable was null - ju" \
"st leave it!");
		return;
	}
	{
		GeeHashSet* _tmp1_;
		GeeIterator* _tmp2_ = NULL;
		GeeIterator* _property_it;
		_tmp1_ = attributes;
		_tmp2_ = gee_abstract_collection_iterator ((GeeAbstractCollection*) _tmp1_);
		_property_it = _tmp2_;
		while (TRUE) {
			GeeIterator* _tmp3_;
			gboolean _tmp4_ = FALSE;
			GeeIterator* _tmp5_;
			gpointer _tmp6_ = NULL;
			gchar* property;
			const gchar* _tmp7_;
			gchar** _tmp8_;
			gchar** _tmp9_ = NULL;
			gchar** input_keys;
			gint input_keys_length1;
			gint _input_keys_size_;
			gchar** _tmp10_;
			gint _tmp10__length1;
			gchar** _tmp11_;
			gint _tmp11__length1;
			gchar** _tmp12_;
			gint _tmp12__length1;
			const gchar* _tmp13_;
			gchar* _tmp14_;
			gchar* search_key;
			GHashTable* _tmp15_;
			const gchar* _tmp16_;
			gconstpointer _tmp17_ = NULL;
			GVariant* _tmp18_;
			GVariant* v;
			GVariant* _tmp19_;
			GVariant* _tmp20_;
			const GVariantType* _tmp21_;
			gboolean _tmp22_ = FALSE;
			_tmp3_ = _property_it;
			_tmp4_ = gee_iterator_next (_tmp3_);
			if (!_tmp4_) {
				break;
			}
			_tmp5_ = _property_it;
			_tmp6_ = gee_iterator_get (_tmp5_);
			property = (gchar*) _tmp6_;
			_tmp7_ = property;
			_tmp9_ = _tmp8_ = g_strsplit (_tmp7_, "-", 0);
			input_keys = _tmp9_;
			input_keys_length1 = _vala_array_length (_tmp8_);
			_input_keys_size_ = input_keys_length1;
			_tmp10_ = input_keys;
			_tmp10__length1 = input_keys_length1;
			_tmp11_ = input_keys;
			_tmp11__length1 = input_keys_length1;
			_tmp12_ = input_keys;
			_tmp12__length1 = input_keys_length1;
			_tmp13_ = (_tmp10_ + (_tmp11__length1 - 1))[0];
			_tmp14_ = g_strdup (_tmp13_);
			search_key = _tmp14_;
			_tmp15_ = data;
			_tmp16_ = search_key;
			_tmp17_ = g_hash_table_lookup (_tmp15_, _tmp16_);
			_tmp18_ = _g_variant_ref0 ((GVariant*) _tmp17_);
			v = _tmp18_;
			_tmp19_ = v;
			if (_tmp19_ == NULL) {
				_g_variant_unref0 (v);
				_g_free0 (search_key);
				input_keys = (_vala_array_free (input_keys, input_keys_length1, (GDestroyNotify) g_free), NULL);
				_g_free0 (property);
				continue;
			}
			_tmp20_ = v;
			_tmp21_ = G_VARIANT_TYPE_STRING;
			_tmp22_ = g_variant_is_of_type (_tmp20_, _tmp21_);
			if (_tmp22_) {
				GVariant* _tmp23_;
				const gchar* _tmp24_ = NULL;
				gchar* _tmp25_ = NULL;
				gchar* update;
				const gchar* _tmp26_;
				gboolean _tmp27_ = FALSE;
				const gchar* _tmp32_;
				const gchar* _tmp33_;
				_tmp23_ = v;
				_tmp24_ = g_variant_get_string (_tmp23_, NULL);
				_tmp25_ = string_strip (_tmp24_);
				update = _tmp25_;
				_tmp26_ = property;
				_tmp27_ = string_contains (_tmp26_, "mpris:artUrl");
				if (_tmp27_) {
					MetadataMenuitem* _tmp28_;
					MetadataMenuitem* metadata;
					MetadataMenuitem* _tmp29_;
					const gchar* _tmp30_;
					const gchar* _tmp31_;
					_tmp28_ = _g_object_ref0 (IS_METADATA_MENUITEM (self) ? ((MetadataMenuitem*) self) : NULL);
					metadata = _tmp28_;
					_tmp29_ = metadata;
					_tmp30_ = update;
					_tmp31_ = property;
					metadata_menuitem_fetch_art (_tmp29_, _tmp30_, _tmp31_);
					_g_object_unref0 (metadata);
					_g_free0 (update);
					_g_variant_unref0 (v);
					_g_free0 (search_key);
					input_keys = (_vala_array_free (input_keys, input_keys_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (property);
					continue;
				}
				_tmp32_ = property;
				_tmp33_ = update;
				dbusmenu_menuitem_property_set ((DbusmenuMenuitem*) self, _tmp32_, _tmp33_);
				_g_free0 (update);
			} else {
				GVariant* _tmp34_;
				const GVariantType* _tmp35_;
				gboolean _tmp36_ = FALSE;
				_tmp34_ = v;
				_tmp35_ = G_VARIANT_TYPE_INT32;
				_tmp36_ = g_variant_is_of_type (_tmp34_, _tmp35_);
				if (_tmp36_) {
					const gchar* _tmp37_;
					GVariant* _tmp38_;
					gint32 _tmp39_ = 0;
					_tmp37_ = property;
					_tmp38_ = v;
					_tmp39_ = g_variant_get_int32 (_tmp38_);
					dbusmenu_menuitem_property_set_int ((DbusmenuMenuitem*) self, _tmp37_, (gint) _tmp39_);
				} else {
					GVariant* _tmp40_;
					const GVariantType* _tmp41_;
					gboolean _tmp42_ = FALSE;
					_tmp40_ = v;
					_tmp41_ = G_VARIANT_TYPE_INT64;
					_tmp42_ = g_variant_is_of_type (_tmp40_, _tmp41_);
					if (_tmp42_) {
						const gchar* _tmp43_;
						GVariant* _tmp44_;
						gint64 _tmp45_ = 0LL;
						_tmp43_ = property;
						_tmp44_ = v;
						_tmp45_ = g_variant_get_int64 (_tmp44_);
						dbusmenu_menuitem_property_set_int ((DbusmenuMenuitem*) self, _tmp43_, (gint) _tmp45_);
					} else {
						GVariant* _tmp46_;
						const GVariantType* _tmp47_;
						gboolean _tmp48_ = FALSE;
						_tmp46_ = v;
						_tmp47_ = G_VARIANT_TYPE_BOOLEAN;
						_tmp48_ = g_variant_is_of_type (_tmp46_, _tmp47_);
						if (_tmp48_) {
							const gchar* _tmp49_;
							GVariant* _tmp50_;
							gboolean _tmp51_ = FALSE;
							_tmp49_ = property;
							_tmp50_ = v;
							_tmp51_ = g_variant_get_boolean (_tmp50_);
							dbusmenu_menuitem_property_set_bool ((DbusmenuMenuitem*) self, _tmp49_, _tmp51_);
						}
					}
				}
			}
			_g_variant_unref0 (v);
			_g_free0 (search_key);
			input_keys = (_vala_array_free (input_keys, input_keys_length1, (GDestroyNotify) g_free), NULL);
			_g_free0 (property);
		}
		_g_object_unref0 (_property_it);
	}
}


gboolean player_item_populated (PlayerItem* self, GeeHashSet* attrs) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (attrs != NULL, FALSE);
	{
		GeeHashSet* _tmp0_;
		GeeIterator* _tmp1_ = NULL;
		GeeIterator* _prop_it;
		_tmp0_ = attrs;
		_tmp1_ = gee_abstract_collection_iterator ((GeeAbstractCollection*) _tmp0_);
		_prop_it = _tmp1_;
		while (TRUE) {
			GeeIterator* _tmp2_;
			gboolean _tmp3_ = FALSE;
			GeeIterator* _tmp4_;
			gpointer _tmp5_ = NULL;
			gchar* prop;
			const gchar* _tmp6_;
			gint _tmp7_ = 0;
			_tmp2_ = _prop_it;
			_tmp3_ = gee_iterator_next (_tmp2_);
			if (!_tmp3_) {
				break;
			}
			_tmp4_ = _prop_it;
			_tmp5_ = gee_iterator_get (_tmp4_);
			prop = (gchar*) _tmp5_;
			_tmp6_ = prop;
			_tmp7_ = dbusmenu_menuitem_property_get_int ((DbusmenuMenuitem*) self, _tmp6_);
			if (_tmp7_ != PLAYER_ITEM_EMPTY) {
				result = TRUE;
				_g_free0 (prop);
				_g_object_unref0 (_prop_it);
				return result;
			}
			_g_free0 (prop);
		}
		_g_object_unref0 (_prop_it);
	}
	result = FALSE;
	return result;
}


PlayerController* player_item_get_owner (PlayerItem* self) {
	PlayerController* result;
	PlayerController* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_owner;
	result = _tmp0_;
	return result;
}


static void player_item_set_owner (PlayerItem* self, PlayerController* value) {
	PlayerController* _tmp0_;
	PlayerController* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_owner);
	self->priv->_owner = _tmp1_;
	g_object_notify ((GObject *) self, "owner");
}


const gchar* player_item_get_item_type (PlayerItem* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_item_type;
	result = _tmp0_;
	return result;
}


static void player_item_set_item_type (PlayerItem* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_item_type);
	self->priv->_item_type = _tmp1_;
	g_object_notify ((GObject *) self, "item-type");
}


static GObject * player_item_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	PlayerItem * self;
	const gchar* _tmp0_;
	parent_class = G_OBJECT_CLASS (player_item_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = PLAYER_ITEM (obj);
	_tmp0_ = self->priv->_item_type;
	dbusmenu_menuitem_property_set ((DbusmenuMenuitem*) self, DBUSMENU_MENUITEM_PROP_TYPE, _tmp0_);
	return obj;
}


static void player_item_class_init (PlayerItemClass * klass) {
	player_item_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PlayerItemPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_player_item_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_player_item_set_property;
	G_OBJECT_CLASS (klass)->constructor = player_item_constructor;
	G_OBJECT_CLASS (klass)->finalize = player_item_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_ITEM_OWNER, g_param_spec_object ("owner", "owner", "owner", TYPE_PLAYER_CONTROLLER, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_ITEM_ITEM_TYPE, g_param_spec_string ("item-type", "item-type", "item-type", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void player_item_instance_init (PlayerItem * self) {
	self->priv = PLAYER_ITEM_GET_PRIVATE (self);
}


static void player_item_finalize (GObject* obj) {
	PlayerItem * self;
	self = PLAYER_ITEM (obj);
	_g_object_unref0 (self->priv->_owner);
	_g_free0 (self->priv->_item_type);
	G_OBJECT_CLASS (player_item_parent_class)->finalize (obj);
}


GType player_item_get_type (void) {
	static volatile gsize player_item_type_id__volatile = 0;
	if (g_once_init_enter (&player_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PlayerItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) player_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PlayerItem), 0, (GInstanceInitFunc) player_item_instance_init, NULL };
		GType player_item_type_id;
		player_item_type_id = g_type_register_static (dbusmenu_menuitem_get_type (), "PlayerItem", &g_define_type_info, 0);
		g_once_init_leave (&player_item_type_id__volatile, player_item_type_id);
	}
	return player_item_type_id__volatile;
}


static void _vala_player_item_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	PlayerItem * self;
	self = PLAYER_ITEM (object);
	switch (property_id) {
		case PLAYER_ITEM_OWNER:
		g_value_set_object (value, player_item_get_owner (self));
		break;
		case PLAYER_ITEM_ITEM_TYPE:
		g_value_set_string (value, player_item_get_item_type (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_player_item_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	PlayerItem * self;
	self = PLAYER_ITEM (object);
	switch (property_id) {
		case PLAYER_ITEM_OWNER:
		player_item_set_owner (self, g_value_get_object (value));
		break;
		case PLAYER_ITEM_ITEM_TYPE:
		player_item_set_item_type (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



