import sys, string, os
from Tkinter import *
from tkFileDialog import *
import tkMessageBox
import fnmatch # TODO why is this here?
from PluginsUtil import *

currentPath = os.path.join(os.path.realpath(__file__), '..') # TODO is this the current working directory or the path to this file? is there a distinction?
cashPath = os.path.join(currentPath, '.cash')
cocosPath = os.path.join(currentPath, '../..')
pluginsPath = os.path.join(cocosPath, 'plugins')
plugins = {}
# list of platforms that are found in each plugin's directory
pluginPlatforms = []

def loadPlugins(rootdir = '.'):
    '''walks the plugins directory, adding each plugin to the plugins dict and updating pluginPlatforms with any new platforms found."
    '''
    for d in os.listdir(rootdir):
        p = os.path.join(rootdir, d)
        if os.path.isdir(p):
            plugins[d] = {'platforms': [], 'path': p}
            for platform in os.listdir(p):
                if (platform.startswith('proj.')):
                    if platform not in pluginPlatforms:
                        pluginPlatforms.append(platform)
                    importPlugin(pluginsPath, d, platform)
                    plugins[d]['platforms'].append(platform)
    return plugins # TODO why return plugins if its a global?


def createImportPluginsFrame(parent, d): 
    '''creates portion of gui that lists found plugins and platforms.
    @param parent: tkinter object to attach more tkinter objects to.
    @param d: directory path shown on the plugin table
    '''
    # TODO where is this used?
    def getProject():
        '''queries for directory string, creates label based off of it'''
        d = askdirectory(parent = parent) # TODO d should be returned somehow, so that it can be updated
        print "here asking"
        Label(group, text = d).pack() # TODO group should be a function parameter

    def processChanges():
        '''callback function that finds any changes made to the gui's check marks and TODO
        '''
        msg = ""
        changes = []
        for check in checks: 
            if(checks[check]['value'] != checks[check]['var'].get()):
                change = {'plugin': checks[check]['plugin'], 'platform': checks[check]['platform']}
                if(checks[check]['value'] == 0):
                    msg += "Add    "
                    change['api'] = 'add'
                else:
                    msg += "Remove "
                    change['api'] = 'rm'
                changes.append(change)
                msg += checks[check]['plugin'] + " " + checks[check]['platform'] + '\n' # TODO string formatting would look cleaner
        if(msg == ""):
            msg = "Warning: No changes on input"
        # TODO should display a different dialog if no changes were found, having yes and no buttons on an error dialog is confusing
        result = tkMessageBox.askquestion("Confirm Plugin Changes", msg, icon = 'warning')
        if result == 'yes':
            for change in changes:
                if change['api'] == 'rm':
                    rmPlugin(d, change['plugin'], change['platform'])
                else:
                    addPlugin(d, change['plugin'], change['platform'])

    group = LabelFrame(parent, text = "Plugins")
    group.grid(row = 1, padx = 10, pady = 10)
    pluginTable = LabelFrame(parent, text = d)
    pluginTable.grid(row = 1, padx = 10, pady = 10)
    i = 0 # TODO i, j tracking should be replaced with enumerate function
    checks = {} # dict of CheckButton -> dict
    for p in pluginPlatforms:
        Label(pluginTable, text = p[5:]).grid(row = 0, column = i + 1) # strips first 5 chars to remove "proj."
        loadedPlugins = getPlugins(d, p)
        j = 0
        for key in plugins:
            Label(pluginTable, text = key).grid(row = j + 1, column = 0)
            checkValue = IntVar()
            check = Checkbutton(pluginTable, variable = checkValue)
            checks[check] = {'platform': p, 'plugin': key, 'value': 0, 'var': checkValue}
            if (p in plugins[key]['platforms']):
                check.grid(row = j + 1, column = i + 1)
                if(key in loadedPlugins):
                    check.select()
                    checks[check]['value'] = 1
            j += 1
        i += 1
    Button(parent, text = "Apply Changes", command = processChanges).grid(row = 1, column = 1, padx = 10, pady = 10)

def isCocosProject(path):
    '''returns true if directory pointed to by path has a 'Classes' subdirectory'''
    for d in os.listdir(path):
        if(d == "Classes"):
            return 1 # TODO should return True or False, not ints
    return 0

def createOpenProjectFrame(parent):
    group = LabelFrame(parent, text = "Root Project")
    group.grid(row = 0,  padx = 10, pady = 10)
    def getProject():
        d = askdirectory(parent = parent)
        if isCocosProject(d):
            createImportPluginsFrame(master, d) # TODO master should be passed into function
        else:
            tkMessageBox.showwarning(
                "Invalid Cocos Project",
                "Cannot detect cocos project in this location\n(%s)" % d
            )
    Button(group, text = "Open ...", command = getProject).pack()


#def main():
# Create Local Cash Folder
if not os.path.exists(cashPath):
    os.makedirs(cashPath)
importPluginX('proj.win8.1-universal')
loadPlugins(pluginsPath)
master = Tk()
master.geometry('500x500');
master.title('pluginx Manager')
createOpenProjectFrame(master)
createImportPluginsFrame(master, 'T:/Cocos2dx/plugin/samples/HelloPlugins') # TODO hardcoded path
master.mainloop()

#if __name__ == "__main__":
#    main()
        

    
