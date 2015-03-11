import win8_1_universal
import wp8


# map to implementations for different platforms
hub = {
        'proj.win8.1-universal':win8_1_universal,
        'proj.wp8':wp8
    }

# TODO why does this not do anything? What is is supposed to do?
def getPluginsProjectWin81Universal():
    return []

def getPlugins(path, platform):
    '''returns a list of plugins found in the platform's vcxproj files for the cocos2d-x project. 
    Returns an empty list if the platform is not supported by program.
    @param path: path to the root of the cocos2d-x project
    @param platform: platform to search 
    '''
    if(platform in hub):
        return hub[platform].getPlugins(path)
    return []

# TODO why does this not do anything? What is is supposed to do?
def addPluginProjectWin81Universal(path, plugin):
    print path, plugin
    return 1

def addPlugin(path, plugin, platform):
    '''rewrites vcxproj files to add plugin to cocos2d-x project found at path, if platform is supported.
    @param path: path to the root of the cocos2d-x project
    @param plugin: name of the plugin to add
    @param: the platform to add the plugin to
    '''
    if(platform in hub):
        return hub[platform].addPlugin(path, plugin)
    return 0

def rmPlugin(path, plugin, platform):
    '''removes plugin from vcxproj files found in cocos2d-x project found at path, if platform is supported.
    @param path: path to the root of the cocos2d-x project
    @param plugin: name of the plugin to remove
    @param: the platform to remove the plugin from
    '''
    if(platform in hub):
        return hub[platform].rmPlugin(path, plugin)
    return 0

def importPlugin(pluginsPath, plugin, platform):
    if(platform in hub):
        return hub[platform].importPlugin(pluginsPath, plugin)
    return 0

def importPluginX(platform):
    if(platform in hub):
        return hub[platform].importPluginX()
    return 0
