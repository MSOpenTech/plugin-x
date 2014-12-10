import win8_1_universal
import wp8


hub={
        'proj.win8.1-universal':win8_1_universal,
        'proj.wp8':wp8
    }
def getPluginsProjectWin81Universal():
    return []

def getPlugins(path, platform):
    if(platform in hub):
        return hub[platform].getPlugins(path)
    return []

def addPluginProjectWin81Universal(path, plugin):
    print path, plugin
    return 1

def addPlugin(path, plugin, platform):
    if(platform in hub):
        return hub[platform].addPlugin(path, plugin)
    return 0

def rmPlugin(path, plugin, platform):
    if(platform in hub):
        return hub[platform].rmPlugin(path, plugin)
    return 0

def importPlugin(pluginsPath, plugin, platform):
    if(platform in hub):
        return hub[platform].importPlugin( pluginsPath, plugin)
    return 0

def importPluginX(platform):
    if(platform in hub):
        return hub[platform].importPluginX()
    return 0
