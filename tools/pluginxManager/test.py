from xml.dom.minidom import parse, parseString

file="C:\\git\\work\\cocos3\\projects\\HelloPlugin\\proj.win8.1-universal\\HelloCpp.WindowsPhone\\HelloCpp.WindowsPhone.vcxproj"
dom=parse(file)
for proj in dom.childNodes:
    PluginManagerItems=None
    for child in proj.getElementsByTagName("ItemDefinitionGroup"):
        ClInclude=child.getElementsByTagName("ClCompile")[0].getElementsByTagName("AdditionalIncludeDirectories")[0].childNodes[0]
        LinkInclude=child.getElementsByTagName("Link")[0].getElementsByTagName("AdditionalLibraryDirectories")[0].childNodes[0]
        LinkLib=child.getElementsByTagName("Link")[0].getElementsByTagName("AdditionalDependencies")[0].childNodes[0]
        pluginLib=u"pluginx.WindowsPhone.lib"
        pluginLibpath=u"$(EngineRoot)\\plugin\\tools\\pluginxManager\\.cash\\pluginx\\proj.win8.1-universal\\$(Platform)\\pluginx.WindowsPhone";
        pluginInclude=u"$(EngineRoot)\\plugin\\protocols\\include";
        #
        print LinkInclude.data
        if pluginInclude not in ClInclude.data:
            ClInclude.data=pluginInclude+u";"+ClInclude.data
        if pluginLib not in LinkLib.data:
            LinkLib.data=pluginLib+u";"+LinkLib.data
        if pluginLibpath not in LinkInclude.data:
            LinkInclude.data=pluginLibpath+u";"+LinkInclude.data
        # print child.toxml()
    for child in proj.getElementsByTagName("ItemGroup"):
        if child.hasAttribute("Label"):
            if "PluginManagerItems" == child.attributes["Label"].value:
                PluginManagerItems = child
                break
    if PluginManagerItems==None:
        PluginManagerItems=dom.createElement("ItemGroup")
        PluginManagerItems.attributes["Label"]="PluginManagerItems"
        proj.appendChild(PluginManagerItems)
    # if len(PluginManagerItems.getElementsByTagName("ProjectReference")) == 0:
    #     ref=dom.createElement("ProjectReference")
    #     ref.attributes["Include"]=u"$(EngineRoot)\\plugin\\protocols\\proj.win8.1-universal\\pluginx\\pluginx.WindowsPhone\\pluginx.WindowsPhone.vcxproj";
    #     refGuid = dom.createElement("Project")
    #     refGuid.appendChild(dom.createTextNode("{DF1EC7A1-795E-40F8-92B7-9F7968B07C6B}"))
    #     ref.appendChild(refGuid)
    #     PluginManagerItems.appendChild(ref)
# print LinkLib
file_handle = open(file,"wb")
dom.writexml(file_handle)
# print dom.toxml()
