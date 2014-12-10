import sys, string, os
from Tkinter import *
from tkFileDialog import *
import tkMessageBox
import fnmatch
from PluginsUtil import *

currentPath = os.path.join(os.path.realpath(__file__), '..')
cashPath=os.path.join(currentPath,'.cash')
cocosPath = os.path.join(currentPath,'../..')
pluginsPath = os.path.join(cocosPath, 'plugins')
# Create Local Cash Folder
if not os.path.exists(cashPath):
    os.makedirs(cashPath)



plugins={}
pluginPlatforms=[]
def loadPlugins(rootdir='.'):
    for d in os.listdir(rootdir):
        p=os.path.join(rootdir,d)
        if os.path.isdir(p):
            plugins[d]={'platforms':[], 'path':p}
            for platform in os.listdir(p):
                if (platform.startswith('proj.')):
                    if platform not in pluginPlatforms:
                        pluginPlatforms.append(platform)
                    importPlugin(pluginsPath, d, platform)
                    plugins[d]['platforms'].append(platform)
    return plugins

importPluginX('proj.win8.1-universal')

loadPlugins(pluginsPath)



master = Tk()

master.geometry('500x500');

master.title('pluginx Manager')

def createImportPluginsFrame(parent, dir):
    group = LabelFrame(parent, text="Plugins")

    group.grid(row=1, padx=10, pady=10)
    def getProject():
        dir=askdirectory(parent=parent)
        Label(group, text=dir).pack()

    pluginTable = LabelFrame(parent, text=dir)
    pluginTable.grid(row=1,padx=10,pady=10)
    i=0
    checks={}
    for p in pluginPlatforms:
        Label(pluginTable, text=p[5:]).grid(row=0,column=i+1)
        loadedPlugins=getPlugins(dir, p)
        j=0
        for key in plugins:
            Label(pluginTable,text=key).grid(row=j+1,column=0)
            checkValue=IntVar()
            check = Checkbutton(pluginTable,variable=checkValue)
            checks[check]={'platform':p,'plugin':key, 'value':0, 'var':checkValue}
            if (p in plugins[key]['platforms']):
                check.grid(row=j+1,column=i+1)
                if(key in loadedPlugins):
                    check.select()
                    checks[check]['value']=1
            j+=1
        i+=1
    def processChanges():
        msg=""
        changes=[]
        for check in checks:
            if(checks[check]['value'] != checks[check]['var'].get()):
                change={'plugin':checks[check]['plugin'],'platform':checks[check]['platform']}
                if(checks[check]['value']==0):
                    msg+="Add    "
                    change['api']='add'
                else:
                    msg+="Remove "
                    change['api']='rm'
                changes.append(change)
                msg+=checks[check]['plugin']+" "+checks[check]['platform']+'\n'
        if(msg==""):
            msg="Warning: No changes on input"
        result=tkMessageBox.askquestion("Confirm Plugin Changes", msg, icon='warning')
        if result=='yes':
            for change in changes:
                if change['api']=='rm':
                    rmPlugin(dir, change['plugin'],change['platform'])
                else:
                    addPlugin(dir, change['plugin'],change['platform'])

    Button(parent,text="Apply Changes",command=processChanges).grid(row=1,column=1, padx=10,pady=10)
def isCocosProject(path):
    for d in os.listdir(path):
        if(d=="Classes"):
            return 1
    return 0

def createOpenProjectFrame(parent):
    group = LabelFrame(parent, text="Root Project")
    group.grid(row=0,  padx=10, pady=10)
    def getProject():
        dir=askdirectory(parent=parent)
        if isCocosProject(dir):
            createImportPluginsFrame(master, dir)
        else:
            tkMessageBox.showwarning(
                "Invalid Cocos Project",
                "Cannot detect cocos project in this location\n(%s)" % dir
            )
    Button(group, text="Open ...", command=getProject).pack()

createOpenProjectFrame(master)
createImportPluginsFrame(master, 'E:/git/work/cocos2d-x/plugin/samples/HelloPlugins')
master.mainloop()
