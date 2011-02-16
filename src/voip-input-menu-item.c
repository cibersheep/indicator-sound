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
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <glib/gi18n.h>
#include "voip-input-menu-item.h"
#include "common-defs.h"

typedef struct _VoipInputMenuItemPrivate VoipInputMenuItemPrivate;

struct _VoipInputMenuItemPrivate {
  ActiveSink* a_sink;
};

#define VOIP_INPUT_MENU_ITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), VOIP_INPUT_MENU_ITEM_TYPE, VoipInputMenuItemPrivate))

/* Prototypes */
static void voip_input_menu_item_class_init (VoipInputMenuItemClass *klass);
static void voip_input_menu_item_init       (VoipInputMenuItem *self);
static void voip_input_menu_item_dispose    (GObject *object);
static void voip_input_menu_item_finalize   (GObject *object);
static void handle_event (DbusmenuMenuitem * mi, const gchar * name,
                          GVariant * value, guint timestamp);

G_DEFINE_TYPE (VoipInputMenuItem, voip_input_menu_item, DBUSMENU_TYPE_MENUITEM);

static void
voip_input_menu_item_class_init (VoipInputMenuItemClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  g_type_class_add_private (klass, sizeof (VoipInputMenuItemPrivate));

  object_class->dispose = voip_input_menu_item_dispose;
  object_class->finalize = voip_input_menu_item_finalize;

  DbusmenuMenuitemClass * mclass = DBUSMENU_MENUITEM_CLASS(klass);
  mclass->handle_event = handle_event;
}

static void
voip_input_menu_item_init (VoipInputMenuItem *self)
{
  g_debug("Building new Slider Menu Item");
  dbusmenu_menuitem_property_set( DBUSMENU_MENUITEM(self),
                                  DBUSMENU_MENUITEM_PROP_TYPE,
                                  DBUSMENU_VOIP_INPUT_MENUITEM_TYPE );
}

static void
voip_input_menu_item_dispose (GObject *object)
{
  G_OBJECT_CLASS (voip_input_menu_item_parent_class)->dispose (object);
  return;
}

static void
voip_input_menu_item_finalize (GObject *object)
{
  G_OBJECT_CLASS (voip_input_menu_item_parent_class)->finalize (object);
}

static void
handle_event (DbusmenuMenuitem * mi,
              const gchar * name,
              GVariant * value,
              guint timestamp)
{
  GVariant* input = NULL;
  input = value;
  if (g_variant_is_of_type(value, G_VARIANT_TYPE_VARIANT) == TRUE) {
    input = g_variant_get_variant(value);
  }

  gboolean volume_input = g_variant_get_double(input);
  if (value != NULL){
    if (IS_VOIP_INPUT_MENU_ITEM (mi)) {
      VoipInputMenuItemPrivate* priv = VOIP_INPUT_MENU_ITEM_GET_PRIVATE (VOIP_INPUT_MENU_ITEM (mi));
      g_debug ("Handle event in the voip input level backend instance - %f", volume_input);
      //active_sink_update_volume (priv->a_sink, volume_input);
      //active_sink_ensure_sink_is_unmuted (priv->a_sink);
    }
  }
}

void
voip_input_menu_item_update (VoipInputMenuItem* item,
                              gdouble update)
{
  GVariant* new_volume = g_variant_new_double(update);
  dbusmenu_menuitem_property_set_variant(DBUSMENU_MENUITEM(item),
                                         DBUSMENU_VOIP_INPUT_MENUITEM_LEVEL,
                                         new_volume);
}

void
voip_input_menu_item_enable (VoipInputMenuItem* item,
                              gboolean active)
{
  dbusmenu_menuitem_property_set_bool( DBUSMENU_MENUITEM(item),
                                       DBUSMENU_MENUITEM_PROP_VISIBLE,
                                       active );
}

VoipInputMenuItem*
voip_input_menu_item_new (ActiveSink* sink)
{
  VoipInputMenuItem *self = g_object_new(VOIP_INPUT_MENU_ITEM_TYPE, NULL);
  VoipInputMenuItemPrivate* priv = VOIP_INPUT_MENU_ITEM_GET_PRIVATE (self);
  priv->a_sink = sink;
  return self;
}