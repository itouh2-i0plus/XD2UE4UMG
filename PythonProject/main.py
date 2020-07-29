# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import os
import json
import unreal
from unreal import Anchors

asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
umg = unreal.MyUMGBlueprintFunctionLibrary


def createWidgetBlueprint(asset_name):
    # type: (object) -> unreal.WidgetBlueprint
    """
        Args:
            asset_name (str):

        Returns:
            unreal.WidgetBlueprint:
    """
    return asset_tools.create_asset(asset_name=asset_name, package_path="/Game/GenericAssets",
                                    asset_class=unreal.WidgetBlueprint,
                                    factory=unreal.WidgetBlueprintFactory())


unreal.log("# python test")

unreal.log("## load json")
json_path = os.path.dirname(__file__) + "/test.json"
print "- json_path=" + json_path
json_open = open(json_path)
json_load = json.load(json_open)
print(json_load)

unreal.log("## create widget")

widget_bp = createWidgetBlueprint("bbb2")

root_canvas_panel = umg.get_root_canvas_panel(widget_bp)

button = umg.create_button(widget_bp, "Button")  # type: unreal.Button
root_canvas_panel.add_child(button)

slot = button.get_editor_property("slot")  # type: unreal.CanvasPanelSlot
anchors = slot.get_anchors()  # type: Anchors
unreal.log(anchors)
offsets = slot.get_offsets()
unreal.log(offsets)

unreal.log("## result")
