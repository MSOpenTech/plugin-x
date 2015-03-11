import os
import subprocess
from xml.dom.minidom import parse, parseString

currentPath = os.path.join(os.path.realpath(__file__), '..')
cashPath = os.path.join(currentPath, '.cash') # TODO duplicates in main.py

def importUniversalSolution(solutionPath, plugin):
    return # TODO why is this return here?
    #check if project is C++ plugin or C# plugin project
    if not os.path.isfile(solutionPath):
        print "Could not locate", solutionPath
        return False
    platforms = ['Win32']
    result = 0
    for platform in platforms:
        destPath = os.path.join(cashPath, plugin, 'proj.win8.1-universal', platform) + '\\' # TODO should replace '\\' with os.path.sep
        result |= subprocess.call(
        ['msbuild',
         solutionPath,
         '/p:Configuration=Debug',
         '/p:Platform=' + platform,
         '/t:Rebuild',
         '/p:OutDir=' + destPath])
    if result != 0:
        return False
    return True

def getPlugins(path):
    '''returns a list of strings that are names for each pluginx plugin found in the in the *.Windows and *.WindowsPhone vcxproj files for the cocos2d-x project
    @param path: path to the root of a cocos2d-x project
    '''
    plugins = []
    projpath = path + '\\proj.win8.1-universal' # TODO should use os.path.join
    for d in os.listdir(projpath):
        if d.endswith('Windows') or d.endswith('WindowsPhone'): # TODO should be using os.path.splitext instead of endswith
            if d.endswith('Windows'): # TODO why is this if statement here? is there a better way then double if statements?
                platform = "Windows"
            else:
                platform = "WindowsPhone"

            projectFile = os.path.join(projpath, d)
            for g in os.listdir(projectFile): # TODO change for loop & if check to filter to avoid break
                if g.endswith('.vcxproj'): # TODO should use os.path.splitext instead of endswith
                    projectFile = os.path.join(projectFile, g) # TODO no guarantee that projectFile is actually set (there might not be a vcxproj file)
                    break
                
            dom = parse(projectFile)
            for project in dom.childNodes: # TODO change to filter if possible, to avoid break
                PluginManagerItems = None # TODO what is this? why is it here?
                for child in project.getElementsByTagName("ItemGroup"):
                    if child.hasAttribute('Label'):
                        if child.attributes["Label"].value.startswith("pluginx:"):
                            plugins.append(child.attributes["Label"].value[8:]) # stripping first 8 chars removes "pluginx:" from front of string
                            break
    print plugins
    return plugins

def addPlugin(path, plugin):
    '''rewrites vcxproj file to add xml elements to include plugins 
    @param path: TODO
    @param plugin:
    '''
    projpath = path + '\\proj.win8.1-universal' # TODO should use os.path.join
    print "Adding Win8.1-Universal Plugin", plugin, "to", path
    for d in os.listdir(projpath):
        if d.endswith('Windows') or d.endswith('WindowsPhone'): # TODO should use os.path.splitext
            if d.endswith('Windows'):
                platform = "Windows"
            else:
                platform = "WindowsPhone"

            projectFile = os.path.join(projpath, d)
            for g in os.listdir(projectFile): # TODO should use filter to avoid break
                if g.endswith('.vcxproj'): # TODO should use os.path.splitext
                    projectFile = os.path.join(projectFile, g)
                    break
                
            dom = parse(projectFile)
            for project in dom.childNodes:
                PluginManagerItems = None
                for child in project.getElementsByTagName("ItemGroup"):
                    if child.hasAttribute('Label'):
                        if "PluginManagerItems" == child.attributes["Label"].value:
                            PluginManagerItems = child
                            break
                if PluginManagerItems == None:
                    PluginManagerItems = dom.createElement("ItemGroup")
                    PluginManagerItems.attributes["Label"] = "PluginManagerItems"
                    project.appendChild(PluginManagerItems)

                deploymentChild = dom.createElement("DeploymentContent")
                deploymentChild.appendChild(dom.createTextNode('True'))
                PluginChild = dom.createElement('None')
                PluginChild.attributes['Label'] = plugin
                PluginChild.appendChild(deploymentChild)
                # TODO add all DLLS
                DllPath = os.path.join(cashPath, plugin, 'proj.win8.1-universal', '$(Platform)', plugin + '.' + platform, plugin + '.' + platform + '.dll')
                PluginChild.attributes["Include"] = DllPath
                PluginManagerItems.appendChild(PluginChild)
                file_handle = open(projectFile, "wb")
                dom.writexml(file_handle)
    return 0

# TODO this doesn't do anything
def rmPlugin(path, plugin):
    return 0

def importPlugin(pluginPath, plugin):
    print "Importing Windows 8.1 Universal Plugin:", plugin
    solutionPath = os.path.join(pluginPath, plugin, "proj.win8.1-universal", plugin + '.sln')
    return importUniversalSolution(solutionPath, plugin)

def importPluginX():
    print "Importing Windows 8.1 Universal Plugin Library:"
    solutionPath = os.path.join(cashPath, "../../../protocols/proj.win8.1-universal/pluginx.sln")
    return importUniversalSolution(solutionPath, 'pluginx')
