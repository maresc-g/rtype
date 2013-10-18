<?xml version="1.0" encoding="UTF-8"?>
<?PowerDesigner AppLocale="UTF16" ID="{60B404C8-41E1-4191-97CB-94795379E9B4}" Label="" LastModificationDate="1382099213" Name="Activity_GameLoop" Objects="78" Symbols="73" Target="C++" TargetLink="Reference" Type="{18112060-1A4B-11D1-83D9-444553540000}" signature="CLD_OBJECT_MODEL" version="15.1.0.2850"?>
<!-- Veuillez ne pas modifier ce fichier -->

<Model xmlns:a="attribute" xmlns:c="collection" xmlns:o="object">

<o:RootObject Id="o1">
<c:Children>
<o:Model Id="o2">
<a:ObjectID>60B404C8-41E1-4191-97CB-94795379E9B4</a:ObjectID>
<a:Name>Activity_GameLoop</a:Name>
<a:Code>Activity_GameLoop</a:Code>
<a:CreationDate>1382089323</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094935</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:PackageOptionsText>[FolderOptions]

[FolderOptions\Class Diagram Objects]
GenerationCheckModel=Yes
GenerationPath=
GenerationOptions=
GenerationTasks=
GenerationTargets=
GenerationSelections=</a:PackageOptionsText>
<a:ModelOptionsText>[ModelOptions]

[ModelOptions\Cld]
CaseSensitive=Yes
DisplayName=Yes
EnableTrans=No
EnableRequirements=No
ShowClss=No
DeftAttr=int
DeftMthd=int
DeftParm=int
DeftCont=
DomnDttp=Yes
DomnChck=No
DomnRule=No
SupportDelay=No
PreviewEditable=Yes
AutoRealize=No
DttpFullName=Yes
DeftClssAttrVisi=private
VBNetPreprocessingSymbols=
CSharpPreprocessingSymbols=

[ModelOptions\Cld\NamingOptionsTemplates]

[ModelOptions\Cld\ClssNamingOptions]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG]

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPCKG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN]

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDDOMN\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS]

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDCLASS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF]

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDINTF\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR]

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDACTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS]

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDUCAS\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT]

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDOBJT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG]

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\SQDMSSG\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP]

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CPDCOMP\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR]

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDATTR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD]

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDMETHOD\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM]

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDPARM\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT]

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPORT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART]

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMPART\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC]

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\CLDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC]

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\UCDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK]

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\GNRLLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK]

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RQLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK]

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\RLZSLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK]

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DEPDLINK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV]

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMACTV\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST]

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\ACDOBST\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT]

[ModelOptions\Cld\ClssNamingOptions\STAT\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\STAT\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE]

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDNODE\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI]

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDCMPI\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC]

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DPDASSC\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR]

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\OOMVAR\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO]

[ModelOptions\Cld\ClssNamingOptions\FILO\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=&quot;\/:*?&lt;&gt;|&quot;
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FILO\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_. &quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ]

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMEOBJ\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK]

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\FRMELNK\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass]

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Name]
Template=
MaxLen=254
Case=M
ValidChar=
InvldChar=
AllValid=Yes
NoAccent=No
DefaultChar=_
Script=.convert_name(%Name%,&quot;_&quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Cld\ClssNamingOptions\DefaultClass\Code]
Template=
MaxLen=254
Case=M
ValidChar=&#39;a&#39;-&#39;z&#39;,&#39;A&#39;-&#39;Z&#39;,&#39;0&#39;-&#39;9&#39;,&quot;_&quot;
InvldChar=&quot; &#39;()+=*/&quot;
AllValid=Yes
NoAccent=Yes
DefaultChar=_
Script=.convert_code(%Code%,&quot; &quot;)
ConvTable=
ConvTablePath=%_HOME%\Fichiers de ressources\Tables de conversion

[ModelOptions\Generate]

[ModelOptions\Generate\Cdm]
CheckModel=Yes
SaveLinks=Yes
NameToCode=No
Notation=2

[ModelOptions\Generate\Pdm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No
BuildTrgr=No
TablePrefix=
RefrUpdRule=RESTRICT
RefrDelRule=RESTRICT
IndxPKName=%TABLE%_PK
IndxAKName=%TABLE%_AK
IndxFKName=%REFR%_FK
IndxThreshold=
ColnFKName=%.3:PARENT%_%COLUMN%
ColnFKNameUse=No

[ModelOptions\Generate\Xsm]
CheckModel=Yes
SaveLinks=Yes
ORMapping=No
NameToCode=No</a:ModelOptionsText>
<c:ObjectLanguage>
<o:Shortcut Id="o3">
<a:ObjectID>B952928B-EB76-4B6A-B294-0B0C03B66418</a:ObjectID>
<a:Name>C++</a:Name>
<a:Code>C++</a:Code>
<a:CreationDate>1382089323</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089323</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:TargetStereotype/>
<a:TargetID>22FB523D-7E45-430F-8069-3A702CF3BE3C</a:TargetID>
<a:TargetClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetClassID>
</o:Shortcut>
</c:ObjectLanguage>
<c:DefaultDiagram>
<o:ActivityDiagram Ref="o4"/>
</c:DefaultDiagram>
<c:Flows>
<o:ActivityFlow Id="o5">
<a:ObjectID>010FF811-F67C-49CB-AC2B-5445B50FE739</a:ObjectID>
<a:CreationDate>1382089479</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089479</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o6"/>
</c:Object1>
<c:Object2>
<o:Start Ref="o7"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o8">
<a:ObjectID>9012FB2A-2433-4DA4-ADCB-8A7F4CC29FE9</a:ObjectID>
<a:CreationDate>1382089835</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089835</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o9"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o6"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o10">
<a:ObjectID>FDC1A7FA-E841-4EC9-9532-5498A2A30A9A</a:ObjectID>
<a:CreationDate>1382089882</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089944</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:End Ref="o11"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o12"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o13">
<a:ObjectID>DC075B6A-02F6-48EE-B9AF-0C24E8421DC7</a:ObjectID>
<a:CreationDate>1382092097</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092097</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:End Ref="o14"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o12"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o15">
<a:ObjectID>70186DA5-D219-459A-9EB8-BFE2B949FA26</a:ObjectID>
<a:CreationDate>1382092126</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092792</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o6"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o16"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o17">
<a:ObjectID>AD11B572-2FE7-4ACD-8C5B-E7669F366CF5</a:ObjectID>
<a:CreationDate>1382092367</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092781</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o18"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o16"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o19">
<a:ObjectID>562E0494-F5E5-476F-901D-11C2755AF637</a:ObjectID>
<a:CreationDate>1382092397</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092397</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o20"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o18"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o21">
<a:ObjectID>0A6D5192-7816-414B-87EA-0B4B3ECC0B30</a:ObjectID>
<a:CreationDate>1382092672</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092672</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o22"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o23"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o24">
<a:ObjectID>28F66E84-7F3C-4D6D-A97A-35E49C795A27</a:ObjectID>
<a:CreationDate>1382092674</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092674</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o25"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o23"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o26">
<a:ObjectID>C2A001BB-3F1B-43A8-876F-D56E293442F5</a:ObjectID>
<a:CreationDate>1382092694</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092694</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Synchronization Ref="o27"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o22"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o28">
<a:ObjectID>E030DB39-0692-4819-A3A6-66B4BF967949</a:ObjectID>
<a:CreationDate>1382092696</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092696</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Synchronization Ref="o27"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o25"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o29">
<a:ObjectID>370B38B2-089A-4E17-8FB3-55395B27B08C</a:ObjectID>
<a:CreationDate>1382092804</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092804</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Synchronization Ref="o16"/>
</c:Object1>
<c:Object2>
<o:Start Ref="o30"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o31">
<a:ObjectID>5C588739-B0BE-4B65-B24E-762EEAEA9536</a:ObjectID>
<a:CreationDate>1382092912</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092912</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o32"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o33"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o34">
<a:ObjectID>B6701F4E-AF72-4AD9-BE76-5AB5B14DC65F</a:ObjectID>
<a:CreationDate>1382092920</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092920</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o35"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o32"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o36">
<a:ObjectID>774FFE28-CF88-4C1E-8F23-1CC01A754869</a:ObjectID>
<a:CreationDate>1382093175</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093175</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Synchronization Ref="o23"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o20"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o37">
<a:ObjectID>1E7D12C0-2EC2-460C-9761-E6D3D4172D4F</a:ObjectID>
<a:CreationDate>1382093602</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093602</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Decision Ref="o38"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o9"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o39">
<a:ObjectID>1A3EACC2-A6C6-4271-8BBA-2E667E7169FF</a:ObjectID>
<a:CreationDate>1382093641</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093708</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ConditionAlias>YES</a:ConditionAlias>
<c:Object1>
<o:Activity Ref="o20"/>
</c:Object1>
<c:Object2>
<o:Decision Ref="o38"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o40">
<a:ObjectID>DE9BE6F8-1CD7-4288-B191-DF1770B43C8C</a:ObjectID>
<a:CreationDate>1382093685</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093703</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ConditionAlias>NO</a:ConditionAlias>
<c:Object1>
<o:Activity Ref="o12"/>
</c:Object1>
<c:Object2>
<o:Decision Ref="o38"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o41">
<a:ObjectID>FF2C85AF-6DB9-4F1D-97DE-95FDFAE8381C</a:ObjectID>
<a:CreationDate>1382093911</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093911</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Decision Ref="o42"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o43"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o44">
<a:ObjectID>44E85E46-4EA2-4097-B033-F0BFFA7F6D2F</a:ObjectID>
<a:CreationDate>1382093929</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093929</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o43"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o35"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o45">
<a:ObjectID>231438D6-B354-4F98-ACE9-25156F3A79FE</a:ObjectID>
<a:CreationDate>1382094135</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094221</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ConditionAlias>YES</a:ConditionAlias>
<c:Object1>
<o:Decision Ref="o46"/>
</c:Object1>
<c:Object2>
<o:Decision Ref="o42"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o47">
<a:ObjectID>84913CF1-6AF7-4014-9A4C-69E8B559CEE1</a:ObjectID>
<a:CreationDate>1382094137</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094215</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ConditionAlias>YES</a:ConditionAlias>
<c:Object1>
<o:Activity Ref="o48"/>
</c:Object1>
<c:Object2>
<o:Decision Ref="o46"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o49">
<a:ObjectID>0CC30843-63DE-409C-BDEA-DDA1D15704D8</a:ObjectID>
<a:CreationDate>1382094139</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094228</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ConditionAlias>NO</a:ConditionAlias>
<c:Object1>
<o:Synchronization Ref="o50"/>
</c:Object1>
<c:Object2>
<o:Decision Ref="o42"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o51">
<a:ObjectID>01DBB745-C8BA-4422-B5D1-66066F9EC259</a:ObjectID>
<a:CreationDate>1382094172</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094172</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o52"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o50"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o53">
<a:ObjectID>72F554D4-7132-494F-9995-C6098225F8CC</a:ObjectID>
<a:CreationDate>1382094175</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094175</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o12"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o50"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o54">
<a:ObjectID>8EE50921-9C01-4A9A-8AEF-D3717C965B67</a:ObjectID>
<a:CreationDate>1382094268</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094268</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o52"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o48"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o55">
<a:ObjectID>5D8E1D80-D96B-4671-8D70-2EEBFC5E8708</a:ObjectID>
<a:CreationDate>1382094736</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094780</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ConditionAlias>NO</a:ConditionAlias>
<c:Object1>
<o:Decision Ref="o38"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o56"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o57">
<a:ObjectID>C3FBA0FA-063C-4CAA-889D-7F38E0E7C4D2</a:ObjectID>
<a:CreationDate>1382094787</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094787</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Synchronization Ref="o56"/>
</c:Object1>
<c:Object2>
<o:Decision Ref="o46"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o58">
<a:ObjectID>A3933F25-1AEC-444C-8DFD-D047EE472D45</a:ObjectID>
<a:CreationDate>1382094798</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094798</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o52"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o56"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o59">
<a:ObjectID>C27B0BF9-3CD7-4BEC-A173-89765E4DE7FF</a:ObjectID>
<a:CreationDate>1382094932</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094932</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o33"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o60"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o61">
<a:ObjectID>396A4C24-44F9-47A5-84CB-743F3EAB3C43</a:ObjectID>
<a:CreationDate>1382094935</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094935</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o60"/>
</c:Object1>
<c:Object2>
<o:Synchronization Ref="o27"/>
</c:Object2>
</o:ActivityFlow>
</c:Flows>
<c:Activities>
<o:Activity Id="o6">
<a:ObjectID>9F714EB4-95B5-4FD2-A4B0-CCFD783890D3</a:ObjectID>
<a:Name>InitializeGame</a:Name>
<a:Code>InitializeGame</a:Code>
<a:CreationDate>1382089447</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382099212</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:Flows>
<o:ActivityFlow Id="o62">
<a:ObjectID>C8AFF006-9AB6-48F6-8D5D-0B3275166909</a:ObjectID>
<a:CreationDate>1382089507</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089507</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:Activity Ref="o63"/>
</c:Object1>
<c:Object2>
<o:Start Ref="o64"/>
</c:Object2>
</o:ActivityFlow>
<o:ActivityFlow Id="o65">
<a:ObjectID>4B95269C-F5A4-47B9-B75C-C87BD4C9F681</a:ObjectID>
<a:CreationDate>1382089712</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089712</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<c:Object1>
<o:End Ref="o66"/>
</c:Object1>
<c:Object2>
<o:Activity Ref="o63"/>
</c:Object2>
</o:ActivityFlow>
</c:Flows>
<c:Activities>
<o:Activity Id="o63">
<a:ObjectID>F611B553-C0B0-4B8A-A858-1F3CBF44F7F7</a:ObjectID>
<a:Name>InitializeLevel</a:Name>
<a:Code>InitializeLevel</a:Code>
<a:CreationDate>1382089503</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089569</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
</o:Activity>
</c:Activities>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
<c:Starts>
<o:Start Id="o64">
<a:ObjectID>9FF24A6C-69CD-4971-A30E-9C09993277D3</a:ObjectID>
<a:Name>Debut_2</a:Name>
<a:Code>Debut_2</a:Code>
<a:CreationDate>1382089468</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089468</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Start>
</c:Starts>
<c:Ends>
<o:End Id="o66">
<a:ObjectID>E7F5057C-F086-46E5-A89E-91A8DBC260E8</a:ObjectID>
<a:Name>Fin_1</a:Name>
<a:Code>Fin_1</a:Code>
<a:CreationDate>1382089471</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089471</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:End>
</c:Ends>
</o:Activity>
<o:Activity Id="o9">
<a:ObjectID>FA077772-0577-447A-975C-E5534996B94A</a:ObjectID>
<a:Name>Launch</a:Name>
<a:Code>Launch</a:Code>
<a:CreationDate>1382089827</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089840</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o12">
<a:ObjectID>6232F216-9792-4290-AF22-211E1D641918</a:ObjectID>
<a:Name>EndGame</a:Name>
<a:Code>EndGame</a:Code>
<a:CreationDate>1382089875</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093703</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o18">
<a:ObjectID>C2A6B145-2F04-45C4-BD42-94691FF4CB77</a:ObjectID>
<a:Name>ReadAllClient</a:Name>
<a:Code>ReadAllClient</a:Code>
<a:CreationDate>1382092364</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092374</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o68"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o20">
<a:ObjectID>7E787A12-7086-4C49-8E9F-8B70903DF307</a:ObjectID>
<a:Name>InfoClient</a:Name>
<a:Code>InfoClient</a:Code>
<a:CreationDate>1382092387</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093708</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o22">
<a:ObjectID>5E2EDB5A-0E09-4522-AE5D-1E6B3EB3E476</a:ObjectID>
<a:Name>MovePlayer</a:Name>
<a:Code>MovePlayer</a:Code>
<a:CreationDate>1382092563</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092570</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o60">
<a:ObjectID>884AD51C-CEB0-4546-AB34-8829136D3C31</a:ObjectID>
<a:Name>SpawnMobs</a:Name>
<a:Code>SpawnMobs</a:Code>
<a:CreationDate>1382092602</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093995</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o25">
<a:ObjectID>230BE2CD-A8A5-4905-A72C-580BFBA53960</a:ObjectID>
<a:Name>Fire</a:Name>
<a:Code>Fire</a:Code>
<a:CreationDate>1382092618</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092679</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o33">
<a:ObjectID>6D44F94C-61CA-46DB-B299-C3CEB85A6556</a:ObjectID>
<a:Name>MoveMobs</a:Name>
<a:Code>MoveMobs</a:Code>
<a:CreationDate>1382092819</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093997</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o32">
<a:ObjectID>0BF64725-1155-42EF-AA92-B3417AF59388</a:ObjectID>
<a:Name>FireMobs</a:Name>
<a:Code>FireMobs</a:Code>
<a:CreationDate>1382092903</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093984</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o35">
<a:ObjectID>80981683-9507-490B-9D05-A334266441DC</a:ObjectID>
<a:Name>MoveLevel</a:Name>
<a:Code>MoveLevel</a:Code>
<a:CreationDate>1382092917</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092931</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o52">
<a:ObjectID>4BD8DED9-3C81-462F-8B08-81B592768F01</a:ObjectID>
<a:Name>SendInfoClient</a:Name>
<a:Code>SendInfoClient</a:Code>
<a:CreationDate>1382092965</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092970</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o68"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o43">
<a:ObjectID>BF2E76EE-BBA1-4D4A-B2CD-513B2BFE7A7E</a:ObjectID>
<a:Name>Collision</a:Name>
<a:Code>Collision</a:Code>
<a:CreationDate>1382093886</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093900</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
<o:Activity Id="o48">
<a:ObjectID>F96179D7-A8F3-48A4-8684-2F02B6AB9B53</a:ObjectID>
<a:Name>NextLevel</a:Name>
<a:Code>NextLevel</a:Code>
<a:CreationDate>1382094116</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094215</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:ActionType>UNDEF</a:ActionType>
<c:OrganizationUnit>
<o:OrganizationUnit Ref="o67"/>
</c:OrganizationUnit>
</o:Activity>
</c:Activities>
<c:Synchronizations>
<o:Synchronization Id="o23">
<a:ObjectID>1DBE86D8-F476-4D01-9BC6-66EABECFE129</a:ObjectID>
<a:Name>Synchronisation_2</a:Name>
<a:Code>Synchronisation_2</a:Code>
<a:CreationDate>1382092653</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092653</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Synchronization>
<o:Synchronization Id="o27">
<a:ObjectID>31FEE4A0-E6B4-4152-B0A1-3A838A5BDFF5</a:ObjectID>
<a:Name>Synchronisation_3</a:Name>
<a:Code>Synchronisation_3</a:Code>
<a:CreationDate>1382092685</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092685</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Synchronization>
<o:Synchronization Id="o16">
<a:ObjectID>B21B3565-D6EB-49DD-BD06-1215AEE16076</a:ObjectID>
<a:Name>Synchronisation_4</a:Name>
<a:Code>Synchronisation_4</a:Code>
<a:CreationDate>1382092753</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092753</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Synchronization>
<o:Synchronization Id="o50">
<a:ObjectID>E52629CD-4F10-4411-910B-1CC97D2CABA3</a:ObjectID>
<a:Name>Synchronisation_5</a:Name>
<a:Code>Synchronisation_5</a:Code>
<a:CreationDate>1382094147</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094228</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Synchronization>
<o:Synchronization Id="o56">
<a:ObjectID>F08E8FE5-61AB-4949-ADFF-EE1857F164D2</a:ObjectID>
<a:Name>Synchronisation_8</a:Name>
<a:Code>Synchronisation_8</a:Code>
<a:CreationDate>1382094773</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094773</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Synchronization>
</c:Synchronizations>
<c:Decisions>
<o:Decision Id="o42">
<a:ObjectID>C932CCE7-25EC-40A9-AB05-BC4145DCEF19</a:ObjectID>
<a:Name>Life</a:Name>
<a:Code>Life</a:Code>
<a:CreationDate>1382093138</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094228</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Decision>
<o:Decision Id="o38">
<a:ObjectID>11638C1D-C7EB-446B-9D91-D58AA091A830</a:ObjectID>
<a:Name>Continue</a:Name>
<a:Code>Continue</a:Code>
<a:CreationDate>1382093599</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094749</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Decision>
<o:Decision Id="o46">
<a:ObjectID>87136214-988B-4224-94C9-B5FE8B2FF524</a:ObjectID>
<a:Name>EndLevel</a:Name>
<a:Code>EndLevel</a:Code>
<a:CreationDate>1382094107</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382094749</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Decision>
</c:Decisions>
<c:OrganizationUnits>
<o:OrganizationUnit Id="o67">
<a:ObjectID>706509F7-2F04-400C-BE46-D183D1F67B09</a:ObjectID>
<a:Name>Game(Thread)</a:Name>
<a:Code>Game_Thread_</a:Code>
<a:CreationDate>1382089341</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382093025</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:OrganizationUnit>
<o:OrganizationUnit Id="o68">
<a:ObjectID>C152BAB5-6186-4519-90B3-BFF241340046</a:ObjectID>
<a:Name>Server</a:Name>
<a:Code>Server</a:Code>
<a:CreationDate>1382092074</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092079</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:OrganizationUnit>
</c:OrganizationUnits>
<c:ActivityDiagrams>
<o:ActivityDiagram Id="o4">
<a:ObjectID>7AA71B02-F969-409E-85CA-1B80D5E011F8</a:ObjectID>
<a:Name>GameLoop</a:Name>
<a:Code>GameLoop</a:Code>
<a:CreationDate>1382089323</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382099212</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:DisplayPreferences>[DisplayPreferences]

[DisplayPreferences\ACD]

[DisplayPreferences\General]
Adjust to text=Yes
Snap Grid=No
Constrain Labels=Yes
Display Grid=No
Show Page Delimiter=Yes
Grid size=0
Graphic unit=2
Window color=255, 255, 255
Background image=
Background mode=8
Watermark image=
Watermark mode=8
Show watermark on screen=No
Gradient mode=0
Gradient end color=255, 255, 255
Show Swimlane=Yes
SwimlaneVert=Yes
TreeVert=No
CompDark=0

[DisplayPreferences\Object]
Mode=2
Trunc Length=40
Word Length=40
Word Text=!&quot;&quot;#$%&amp;&#39;()*+,-./:;&lt;=&gt;?@[\]^_`{|}~
Shortcut IntIcon=Yes
Shortcut IntLoct=Yes
Shortcut IntFullPath=No
Shortcut IntLastPackage=Yes
Shortcut ExtIcon=Yes
Shortcut ExtLoct=No
Shortcut ExtFullPath=No
Shortcut ExtLastPackage=Yes
Shortcut ExtIncludeModl=Yes
EObjShowStrn=Yes
ExtendedObject.Comment=No
ExtendedObject.IconPicture=No
ExtendedObject_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom de l&amp;#39;objet&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF] &lt;Separator Name=&quot;Séparateur&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Commentaire&quot; Attribute=&quot;Comment&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;LEFT&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
ELnkShowStrn=Yes
ELnkShowName=Yes
ExtendedLink_SymbolLayout=&lt;Form&gt;[CRLF] &lt;Form Name=&quot;Centre&quot; &gt;[CRLF]  &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF]  &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;/Form&gt;[CRLF] &lt;Form Name=&quot;Source&quot; &gt;[CRLF] &lt;/Form&gt;[CRLF] &lt;Form Name=&quot;Destination&quot; &gt;[CRLF] &lt;/Form&gt;[CRLF]&lt;/Form&gt;
FileObject.Stereotype=No
FileObject.DisplayName=Yes
FileObject.LocationOrName=No
FileObject.IconPicture=No
FileObject.IconMode=Yes
FileObject_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;ExclusiveChoice Name=&quot;Choix exclusif&quot; Mandatory=&quot;Yes&quot; Display=&quot;HorizontalRadios&quot; &gt;[CRLF]  &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF]  &lt;StandardAttribute Name=&quot;Emplacement&quot; Attribute=&quot;LocationOrName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;/ExclusiveChoice&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
PckgShowStrn=Yes
Package.Comment=No
Package.IconPicture=No
Package_SymbolLayout=
Display Model Version=Yes
Activity.Stereotype=Yes
Activity.Comment=No
Activity.ParametersDisplay=Yes
Activity.IconPicture=No
Activity.SubSymbols=Yes
Activity_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF] &lt;Separator Name=&quot;Séparateur&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Commentaire&quot; Attribute=&quot;Comment&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;LEFT&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
ObjectNode.Stereotype=Yes
ObjectNode.Comment=No
ObjectNode.IconPicture=No
ObjectNode_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;Name&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Etat&quot; Attribute=&quot;States&quot; Prefix=&quot;[&quot; Suffix=&quot;]&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Commentaire&quot; Attribute=&quot;Comment&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;LEFT&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
Variable.Stereotype=Yes
Variable.Comment=No
Variable.IconPicture=No
Variable_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF] &lt;Separator Name=&quot;Séparateur&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Commentaire&quot; Attribute=&quot;Comment&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;LEFT&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
ActivityParameter.DisplayName=Yes
ActivityParameter.InstanceDisplay=No
ActivityParameter.IconPicture=No
ActivityParameter_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;Separator Name=&quot;Séparateur&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
Start.Stereotype=Yes
Start.DisplayName=No
Start.IconPicture=No
Start_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;Separator Name=&quot;Séparateur&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
End.Stereotype=Yes
End.DisplayName=No
End.IconPicture=No
End_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Nom&quot; Attribute=&quot;DisplayName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;Separator Name=&quot;Séparateur&quot; /&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
Decision.Stereotype=Yes
Decision.DisplayedExpression=No
Decision.DisplayedExpressionOrName=Yes
Decision.IconPicture=No
Decision_SymbolLayout=&lt;Form&gt;[CRLF] &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;ExclusiveChoice Name=&quot;Choix exclusif&quot; Mandatory=&quot;Yes&quot; Display=&quot;HorizontalRadios&quot; &gt;[CRLF]  &lt;StandardAttribute Name=&quot;Expression&quot; Attribute=&quot;DisplayedExpression&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF]  &lt;StandardAttribute Name=&quot;Nom en l&amp;#39;absence de condition&quot; Attribute=&quot;DisplayedExpressionOrName&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;/ExclusiveChoice&gt;[CRLF] &lt;StandardAttribute Name=&quot;Icône&quot; Attribute=&quot;IconPicture&quot; Prefix=&quot;&quot; Suffix=&quot;&quot; Alignment=&quot;CNTR&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF]&lt;/Form&gt;
Synchronization.IconPicture=No
Synchronization_SymbolLayout=
OrganizationUnit.Stereotype=Yes
OrganizationUnit.IconPicture=No
OrganizationUnit_SymbolLayout=
ActivityFlow.Stereotype=Yes
ActivityFlow_SymbolLayout=&lt;Form&gt;[CRLF] &lt;Form Name=&quot;Source&quot; &gt;[CRLF]  &lt;StandardAttribute Name=&quot;Condition&quot; Attribute=&quot;DisplayedCondition&quot; Prefix=&quot;[&quot; Suffix=&quot;]&quot; Caption=&quot;&quot; Mandatory=&quot;Yes&quot; /&gt;[CRLF] &lt;/Form&gt;[CRLF] &lt;Form Name=&quot;Destination&quot; &gt;[CRLF]  &lt;StandardAttribute Name=&quot;Stéréotype&quot; Attribute=&quot;Stereotype&quot; Prefix=&quot;&amp;lt;&amp;lt;&quot; Suffix=&quot;&amp;gt;&amp;gt;&quot; Caption=&quot;&quot; Mandatory=&quot;No&quot; /&gt;[CRLF] &lt;/Form&gt;[CRLF] &lt;Form Name=&quot;Centre&quot; &gt;[CRLF] &lt;/Form&gt;[CRLF]&lt;/Form&gt;

[DisplayPreferences\Symbol]

[DisplayPreferences\Symbol\FRMEOBJ]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=6000
Height=2000
Brush color=255 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=64
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 255 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FRMELNK]
CENTERFont=Arial,8,N
CENTERFont color=0, 0, 0
Line style=1
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\FILO]
OBJSTRNFont=Arial,8,N
OBJSTRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LCNMFont=Arial,8,N
LCNMFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\CLDPCKG]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4800
Height=3600
Brush color=255 255 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 178 178 178
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMACTV]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=6000
Height=2000
Brush color=192 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 192
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\ACDOBST]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
NAMEFont=Arial,8,N
NAMEFont color=0, 0, 0
STATFont=Arial,8,N
STATFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4000
Height=3000
Brush color=224 224 224
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMVAR]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
LABLFont=Arial,8,N
LABLFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=4000
Height=3000
Brush color=224 224 224
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=2 0 128 128 128
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMATPM]
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=Yes
Width=800
Height=800
Brush color=192 255 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 192
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMSTRT]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=Yes
Keep center=Yes
Keep size=Yes
Width=1200
Height=1200
Brush color=0 128 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 192
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMEND]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=Yes
Keep center=Yes
Keep size=Yes
Width=1500
Height=1500
Brush color=0 128 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=65
Brush gradient color=192 192 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 192
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMDCSN]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DEXPFont=Arial,8,N
DEXPFont color=0, 0, 0
DEXNFont=Arial,8,N
DEXNFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=Yes
Keep size=No
Width=6600
Height=4000
Brush color=255 255 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=512
Brush gradient color=255 255 255
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 128 128 0
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMSYNC]
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Width=2400
Height=1500
Brush color=0 128 192
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=512
Brush gradient color=0 128 192
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 192
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMORGN]
STRNFont=Arial,8,N
STRNFont color=0, 0, 0
DISPNAMEFont=Arial,8,N
DISPNAMEFont color=0, 0, 0
AutoAdjustToText=Yes
Keep aspect=Yes
Keep center=Yes
Keep size=No
Width=3200
Height=4800
Brush color=242 242 255
Fill Color=Yes
Brush style=6
Brush bitmap mode=12
Brush gradient mode=512
Brush gradient color=200 216 248
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 192
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\OOMFLOW]
SOURCEFont=Arial,8,N
SOURCEFont color=0, 0, 0
DESTINATIONFont=Arial,8,N
DESTINATIONFont color=0, 0, 0
Line style=1
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\USRDEPD]
OBJXSTRFont=Arial,8,N
OBJXSTRFont color=0, 0, 0
Line style=1
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=2 0 128 128 255
Shadow color=192 192 192
Shadow=0

[DisplayPreferences\Symbol\Free Symbol]
Free TextFont=Arial,8,N
Free TextFont color=0, 0, 0
Line style=0
AutoAdjustToText=Yes
Keep aspect=No
Keep center=No
Keep size=No
Brush color=255 255 255
Fill Color=Yes
Brush style=1
Brush bitmap mode=12
Brush gradient mode=0
Brush gradient color=118 118 118
Brush background image=
Custom shape=
Custom text mode=0
Pen=1 0 0 0 255
Shadow color=192 192 192
Shadow=0</a:DisplayPreferences>
<a:PaperSize>(8268, 11693)</a:PaperSize>
<a:PageMargins>((315,354), (433,354))</a:PageMargins>
<a:PageOrientation>1</a:PageOrientation>
<a:PaperSource>15</a:PaperSource>
<c:Symbols>
<o:FlowSymbol Id="o69">
<a:CreationDate>1382092097</a:CreationDate>
<a:ModificationDate>1382094642</a:ModificationDate>
<a:Rect>((7160,-14383), (13659,-13933))</a:Rect>
<a:ListOfPoints>((7160,-14156),(13659,-14160))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o70"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:EndSymbol Ref="o71"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o13"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o72">
<a:CreationDate>1382092126</a:CreationDate>
<a:ModificationDate>1382099213</a:ModificationDate>
<a:Rect>((960,16459), (14380,22020))</a:Rect>
<a:ListOfPoints>((14380,22020),(960,22020),(960,16459))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o73"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o74"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o15"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o75">
<a:CreationDate>1382092397</a:CreationDate>
<a:ModificationDate>1382094642</a:ModificationDate>
<a:Rect>((4340,6180), (14860,10920))</a:Rect>
<a:ListOfPoints>((14860,10920),(14860,6180),(4340,6180))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o76"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o77"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o19"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o78">
<a:CreationDate>1382094172</a:CreationDate>
<a:ModificationDate>1382094642</a:ModificationDate>
<a:Rect>((6360,-9240), (13740,-7680))</a:Rect>
<a:ListOfPoints>((6360,-7680),(6360,-9240),(13740,-9240))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o79"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o80"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o51"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o81">
<a:CreationDate>1382094268</a:CreationDate>
<a:ModificationDate>1382094642</a:ModificationDate>
<a:Rect>((-8160,-11790), (16920,-9630))</a:Rect>
<a:ListOfPoints>((-8160,-11790),(-8160,-9630),(16920,-9630))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o82"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o80"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o54"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o83">
<a:CreationDate>1382094798</a:CreationDate>
<a:ModificationDate>1382094819</a:ModificationDate>
<a:Rect>((-16740,-9000), (13740,-6840))</a:Rect>
<a:ListOfPoints>((-16740,-6840),(-16740,-9000),(13740,-9000))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o84"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o80"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o58"/>
</c:Object>
</o:FlowSymbol>
<o:SwimlaneGroupSymbol Id="o85">
<a:CreationDate>1382089341</a:CreationDate>
<a:ModificationDate>1382094642</a:ModificationDate>
<a:Rect>((-24660,-15720), (20199,25378))</a:Rect>
<a:LineColor>0</a:LineColor>
<c:SubSymbols>
<o:SwimlaneSymbol Id="o86">
<a:CreationDate>1382089341</a:CreationDate>
<a:ModificationDate>1382099212</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-24660,-15720), (10080,25378))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16773874</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>16308424</a:GradientEndColor>
<a:KeepAspect>1</a:KeepAspect>
<a:KeepCenter>1</a:KeepCenter>
<c:SubSymbols>
<o:FlowSymbol Id="o87">
<a:CreationDate>1382089835</a:CreationDate>
<a:ModificationDate>1382099213</a:ModificationDate>
<a:Rect>((-16030,16200), (-4380,21120))</a:Rect>
<a:ListOfPoints>((-4380,16200),(-6735,16200),(-6735,21120),(-16030,21120))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o74"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o88"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o8"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o89">
<a:CreationDate>1382094935</a:CreationDate>
<a:ModificationDate>1382094935</a:ModificationDate>
<a:Rect>((-16260,8100), (-15300,10440))</a:Rect>
<a:ListOfPoints>((-15300,8100),(-16260,8100),(-16260,10440))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o90"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o91"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o61"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o92">
<a:CreationDate>1382094932</a:CreationDate>
<a:ModificationDate>1382094932</a:ModificationDate>
<a:Rect>((-19215,2820), (-18765,9540))</a:Rect>
<a:ListOfPoints>((-18990,9540),(-18990,2820))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o91"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o93"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o59"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o94">
<a:CreationDate>1382094787</a:CreationDate>
<a:ModificationDate>1382094793</a:ModificationDate>
<a:Rect>((-17220,-6720), (-12900,-4560))</a:Rect>
<a:ListOfPoints>((-12900,-4560),(-17220,-4560),(-17220,-6720))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseDecisionSymbol Ref="o95"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseSynchronizationSymbol Ref="o84"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o57"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o96">
<a:CreationDate>1382094736</a:CreationDate>
<a:ModificationDate>1382094804</a:ModificationDate>
<a:SourceTextOffset>(4740, 1340)</a:SourceTextOffset>
<a:Rect>((-22800,-6720), (-13220,15959))</a:Rect>
<a:ListOfPoints>((-17760,-6720),(-22800,-6720),(-22800,15959),(-13220,15959))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o84"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseDecisionSymbol Ref="o97"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o55"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o98">
<a:CreationDate>1382094175</a:CreationDate>
<a:ModificationDate>1382094175</a:ModificationDate>
<a:Rect>((4635,-13080), (5085,-7620))</a:Rect>
<a:ListOfPoints>((4860,-7620),(4860,-13080))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o79"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o70"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o53"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o99">
<a:CreationDate>1382094139</a:CreationDate>
<a:ModificationDate>1382094233</a:ModificationDate>
<a:SourceTextOffset>(780, -840)</a:SourceTextOffset>
<a:Rect>((-260,-7376), (5565,-4380))</a:Rect>
<a:ListOfPoints>((-260,-4380),(5565,-4380),(5565,-7376))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseDecisionSymbol Ref="o100"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseSynchronizationSymbol Ref="o79"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o49"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o101">
<a:CreationDate>1382094137</a:CreationDate>
<a:ModificationDate>1382094604</a:ModificationDate>
<a:SourceTextOffset>(1440, 260)</a:SourceTextOffset>
<a:Rect>((-10035,-11340), (-6780,-6540))</a:Rect>
<a:ListOfPoints>((-9660,-6540),(-9660,-8479),(-9960,-8479),(-9960,-11340))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseDecisionSymbol Ref="o95"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o82"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o47"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o102">
<a:CreationDate>1382094135</a:CreationDate>
<a:ModificationDate>1382094594</a:ModificationDate>
<a:Rect>((-7639,-4560), (-3527,-2400))</a:Rect>
<a:ListOfPoints>((-3527,-2400),(-4960,-2400),(-4960,-4560),(-6393,-4560))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseDecisionSymbol Ref="o100"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseDecisionSymbol Ref="o95"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o45"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o103">
<a:CreationDate>1382093929</a:CreationDate>
<a:ModificationDate>1382094666</a:ModificationDate>
<a:Rect>((-7520,-600), (1300,1200))</a:Rect>
<a:ListOfPoints>((-7520,-600),(-7520,1200),(1300,1200))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o104"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o105"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o44"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o106">
<a:CreationDate>1382093911</a:CreationDate>
<a:ModificationDate>1382093939</a:ModificationDate>
<a:Rect>((3007,-2400), (5320,1710))</a:Rect>
<a:ListOfPoints>((5320,1710),(5320,-2400),(3007,-2400))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o105"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseDecisionSymbol Ref="o100"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o41"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o107">
<a:CreationDate>1382093685</a:CreationDate>
<a:ModificationDate>1382094442</a:ModificationDate>
<a:Rect>((-24020,-14100), (2260,17939))</a:Rect>
<a:ListOfPoints>((-16487,17939),(-24020,17939),(-24020,-14100),(2260,-14100))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseDecisionSymbol Ref="o97"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o70"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o40"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o108">
<a:CreationDate>1382093641</a:CreationDate>
<a:ModificationDate>1382099215</a:ModificationDate>
<a:SourceTextOffset>(1800, -1860)</a:SourceTextOffset>
<a:Rect>((-9953,6299), (2719,17939))</a:Rect>
<a:ListOfPoints>((-9953,17939),(-9953,9720),(2719,9720),(2719,6299))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseDecisionSymbol Ref="o97"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o77"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o39"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o109">
<a:CreationDate>1382093602</a:CreationDate>
<a:ModificationDate>1382098539</a:ModificationDate>
<a:Rect>((-16220,19919), (-13220,22260))</a:Rect>
<a:ListOfPoints>((-16220,22260),(-14720,22260),(-14720,19919),(-13220,19919))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o88"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseDecisionSymbol Ref="o97"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o37"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o110">
<a:CreationDate>1382093175</a:CreationDate>
<a:ModificationDate>1382093621</a:ModificationDate>
<a:Rect>((-2780,5895), (460,6345))</a:Rect>
<a:ListOfPoints>((460,6120),(-2780,6120))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o77"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseSynchronizationSymbol Ref="o111"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o36"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o112">
<a:CreationDate>1382092920</a:CreationDate>
<a:ModificationDate>1382094927</a:ModificationDate>
<a:Rect>((-15620,-2130), (-12440,-510))</a:Rect>
<a:ListOfPoints>((-15620,-2130),(-15620,-510),(-12440,-510))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o113"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o104"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o34"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o114">
<a:CreationDate>1382092912</a:CreationDate>
<a:ModificationDate>1382094927</a:ModificationDate>
<a:Rect>((-18930,-1800), (-18480,3179))</a:Rect>
<a:ListOfPoints>((-18855,3179),(-18855,869),(-18555,869),(-18555,-1800))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o93"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o113"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o31"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o115">
<a:CreationDate>1382092696</a:CreationDate>
<a:ModificationDate>1382094921</a:ModificationDate>
<a:Rect>((-15220,2040), (-9760,5760))</a:Rect>
<a:ListOfPoints>((-9760,2040),(-9760,5760),(-15220,5760))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o116"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseSynchronizationSymbol Ref="o90"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o28"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o117">
<a:CreationDate>1382092694</a:CreationDate>
<a:ModificationDate>1382094917</a:ModificationDate>
<a:Rect>((-15220,6720), (-12700,7740))</a:Rect>
<a:ListOfPoints>((-12700,7740),(-13615,7740),(-13615,6720),(-15220,6720))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o118"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseSynchronizationSymbol Ref="o90"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o26"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o119">
<a:CreationDate>1382092674</a:CreationDate>
<a:ModificationDate>1382094668</a:ModificationDate>
<a:Rect>((-7240,2460), (-2620,4980))</a:Rect>
<a:ListOfPoints>((-2620,4980),(-2620,2460),(-7240,2460))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o111"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o116"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o24"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o120">
<a:CreationDate>1382092672</a:CreationDate>
<a:ModificationDate>1382094663</a:ModificationDate>
<a:Rect>((-7240,6600), (-2560,7740))</a:Rect>
<a:ListOfPoints>((-2560,6600),(-2560,7740),(-7240,7740))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o111"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o118"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o21"/>
</c:Object>
</o:FlowSymbol>
<o:ActivitySymbol Id="o88">
<a:CreationDate>1382089827</a:CreationDate>
<a:ModificationDate>1382094439</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-19180,20780), (-13181,22779))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o9"/>
</c:Object>
</o:ActivitySymbol>
<o:ActivitySymbol Id="o70">
<a:CreationDate>1382089875</a:CreationDate>
<a:ModificationDate>1382092085</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((1580,-14920), (7579,-12921))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o12"/>
</c:Object>
</o:ActivitySymbol>
<o:ActivitySymbol Id="o77">
<a:CreationDate>1382092387</a:CreationDate>
<a:ModificationDate>1382093621</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-280,5300), (5719,7299))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o20"/>
</c:Object>
</o:ActivitySymbol>
<o:ActivitySymbol Id="o118">
<a:CreationDate>1382092563</a:CreationDate>
<a:ModificationDate>1382094663</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-12760,6440), (-6761,8439))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o22"/>
</c:Object>
</o:ActivitySymbol>
<o:ActivitySymbol Id="o91">
<a:CreationDate>1382092602</a:CreationDate>
<a:ModificationDate>1382094923</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-21940,9440), (-15941,11439))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o60"/>
</c:Object>
</o:ActivitySymbol>
<o:ActivitySymbol Id="o116">
<a:CreationDate>1382092618</a:CreationDate>
<a:ModificationDate>1382094668</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-11980,1760), (-5981,3759))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o25"/>
</c:Object>
</o:ActivitySymbol>
<o:BaseSynchronizationSymbol Id="o111">
<a:CreationDate>1382092653</a:CreationDate>
<a:ModificationDate>1382093621</a:ModificationDate>
<a:Rect>((-3250,4648), (-1751,7736))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>12615680</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Synchronization Ref="o23"/>
</c:Object>
</o:BaseSynchronizationSymbol>
<o:BaseSynchronizationSymbol Id="o90">
<a:CreationDate>1382092685</a:CreationDate>
<a:ModificationDate>1382094917</a:ModificationDate>
<a:Rect>((-15970,5249), (-14471,8337))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>12615680</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Synchronization Ref="o27"/>
</c:Object>
</o:BaseSynchronizationSymbol>
<o:ActivitySymbol Id="o93">
<a:CreationDate>1382092819</a:CreationDate>
<a:ModificationDate>1382094924</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-21460,2180), (-15461,4179))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o33"/>
</c:Object>
</o:ActivitySymbol>
<o:ActivitySymbol Id="o113">
<a:CreationDate>1382092903</a:CreationDate>
<a:ModificationDate>1382094927</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-21300,-3160), (-15301,-1161))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o32"/>
</c:Object>
</o:ActivitySymbol>
<o:ActivitySymbol Id="o104">
<a:CreationDate>1382092917</a:CreationDate>
<a:ModificationDate>1382094666</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-12860,-1480), (-6861,519))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o35"/>
</c:Object>
</o:ActivitySymbol>
<o:BaseDecisionSymbol Id="o100">
<a:CreationDate>1382093138</a:CreationDate>
<a:ModificationDate>1382093939</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-3560,-4400), (3039,-401))</a:Rect>
<a:LineColor>32896</a:LineColor>
<a:FillColor>12648447</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DEXP 0 Arial,8,N
DEXN 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:KeepCenter>1</a:KeepCenter>
<c:Object>
<o:Decision Ref="o42"/>
</c:Object>
</o:BaseDecisionSymbol>
<o:BaseDecisionSymbol Id="o97">
<a:CreationDate>1382093599</a:CreationDate>
<a:ModificationDate>1382094442</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-16520,15940), (-9921,19939))</a:Rect>
<a:LineColor>32896</a:LineColor>
<a:FillColor>12648447</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DEXP 0 Arial,8,N
DEXN 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:KeepCenter>1</a:KeepCenter>
<c:Object>
<o:Decision Ref="o38"/>
</c:Object>
</o:BaseDecisionSymbol>
<o:ActivitySymbol Id="o105">
<a:CreationDate>1382093886</a:CreationDate>
<a:ModificationDate>1382093919</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((160,440), (6159,2439))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o43"/>
</c:Object>
</o:ActivitySymbol>
<o:BaseDecisionSymbol Id="o95">
<a:CreationDate>1382094107</a:CreationDate>
<a:ModificationDate>1382094594</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-12960,-6560), (-6361,-2561))</a:Rect>
<a:LineColor>32896</a:LineColor>
<a:FillColor>12648447</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DEXP 0 Arial,8,N
DEXN 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:KeepCenter>1</a:KeepCenter>
<c:Object>
<o:Decision Ref="o46"/>
</c:Object>
</o:BaseDecisionSymbol>
<o:ActivitySymbol Id="o82">
<a:CreationDate>1382094116</a:CreationDate>
<a:ModificationDate>1382094596</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-11460,-12400), (-5461,-10401))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o48"/>
</c:Object>
</o:ActivitySymbol>
<o:BaseSynchronizationSymbol Id="o79">
<a:CreationDate>1382094147</a:CreationDate>
<a:ModificationDate>1382094165</a:ModificationDate>
<a:Rect>((4142,-8387), (7096,-6887))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>12615680</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Synchronization Ref="o50"/>
</c:Object>
</o:BaseSynchronizationSymbol>
<o:BaseSynchronizationSymbol Id="o84">
<a:CreationDate>1382094773</a:CreationDate>
<a:ModificationDate>1382094782</a:ModificationDate>
<a:Rect>((-18420,-7470), (-16021,-5971))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>12615680</a:GradientEndColor>
<c:Object>
<o:Synchronization Ref="o56"/>
</c:Object>
</o:BaseSynchronizationSymbol>
<o:ActivitySymbol Id="o74">
<a:CreationDate>1382089447</a:CreationDate>
<a:ModificationDate>1382099213</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-4980,11760), (6900,21159))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:SubSymbols>
<o:FlowSymbol Id="o121">
<a:CreationDate>1382089712</a:CreationDate>
<a:ModificationDate>1382099209</a:ModificationDate>
<a:Rect>((-3600,13979), (2520,15720))</a:Rect>
<a:ListOfPoints>((2520,15720),(2520,13979),(-3600,13979))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:ActivitySymbol Ref="o122"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:EndSymbol Ref="o123"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o65"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o124">
<a:CreationDate>1382089507</a:CreationDate>
<a:ModificationDate>1382099209</a:ModificationDate>
<a:Rect>((-3540,16499), (120,17699))</a:Rect>
<a:ListOfPoints>((-3540,17699),(-3540,16499),(120,16499))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:StartSymbol Ref="o125"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o122"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o62"/>
</c:Object>
</o:FlowSymbol>
<o:StartSymbol Id="o125">
<a:CreationDate>1382089468</a:CreationDate>
<a:ModificationDate>1382099212</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-4140,17100), (-2941,18299))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>12632256</a:GradientEndColor>
<a:KeepAspect>1</a:KeepAspect>
<a:KeepCenter>1</a:KeepCenter>
<a:KeepSize>1</a:KeepSize>
<c:Object>
<o:Start Ref="o64"/>
</c:Object>
</o:StartSymbol>
<o:EndSymbol Id="o123">
<a:CreationDate>1382089471</a:CreationDate>
<a:ModificationDate>1382099212</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-4350,13230), (-2851,14729))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>12632256</a:GradientEndColor>
<a:KeepAspect>1</a:KeepAspect>
<a:KeepCenter>1</a:KeepCenter>
<a:KeepSize>1</a:KeepSize>
<c:Object>
<o:End Ref="o66"/>
</c:Object>
</o:EndSymbol>
<o:ActivitySymbol Id="o122">
<a:CreationDate>1382089503</a:CreationDate>
<a:ModificationDate>1382099212</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((-780,15560), (5219,17559))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o63"/>
</c:Object>
</o:ActivitySymbol>
</c:SubSymbols>
<c:Object>
<o:Activity Ref="o6"/>
</c:Object>
</o:ActivitySymbol>
</c:SubSymbols>
<c:Object>
<o:OrganizationUnit Ref="o67"/>
</c:Object>
</o:SwimlaneSymbol>
<o:SwimlaneSymbol Id="o126">
<a:CreationDate>1382092074</a:CreationDate>
<a:ModificationDate>1382094642</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((10080,-15720), (20199,25378))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16773874</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>16308424</a:GradientEndColor>
<a:KeepAspect>1</a:KeepAspect>
<a:KeepCenter>1</a:KeepCenter>
<c:SubSymbols>
<o:FlowSymbol Id="o127">
<a:CreationDate>1382092804</a:CreationDate>
<a:ModificationDate>1382092804</a:ModificationDate>
<a:Rect>((14800,21922), (17319,22402))</a:Rect>
<a:ListOfPoints>((17319,22199),(14800,22124))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:StartSymbol Ref="o128"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:BaseSynchronizationSymbol Ref="o73"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o29"/>
</c:Object>
</o:FlowSymbol>
<o:FlowSymbol Id="o129">
<a:CreationDate>1382092367</a:CreationDate>
<a:ModificationDate>1382092781</a:ModificationDate>
<a:Rect>((14739,10859), (15399,21419))</a:Rect>
<a:ListOfPoints>((14739,21419),(14739,14929),(15399,14929),(15399,10859))</a:ListOfPoints>
<a:CornerStyle>1</a:CornerStyle>
<a:ArrowStyle>1</a:ArrowStyle>
<a:LineColor>16744448</a:LineColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>SOURCE 0 Arial,8,N
DESTINATION 0 Arial,8,N</a:FontList>
<c:SourceSymbol>
<o:BaseSynchronizationSymbol Ref="o73"/>
</c:SourceSymbol>
<c:DestinationSymbol>
<o:ActivitySymbol Ref="o76"/>
</c:DestinationSymbol>
<c:Object>
<o:ActivityFlow Ref="o17"/>
</c:Object>
</o:FlowSymbol>
<o:EndSymbol Id="o71">
<a:CreationDate>1382092088</a:CreationDate>
<a:ModificationDate>1382092103</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((12910,-14910), (14409,-13411))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>12632256</a:GradientEndColor>
<a:KeepAspect>1</a:KeepAspect>
<a:KeepCenter>1</a:KeepCenter>
<a:KeepSize>1</a:KeepSize>
<c:Object>
<o:End Ref="o14"/>
</c:Object>
</o:EndSymbol>
<o:StartSymbol Id="o128">
<a:CreationDate>1382092090</a:CreationDate>
<a:ModificationDate>1382092749</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((16720,21600), (17919,22799))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>12632256</a:GradientEndColor>
<a:KeepAspect>1</a:KeepAspect>
<a:KeepCenter>1</a:KeepCenter>
<a:KeepSize>1</a:KeepSize>
<c:Object>
<o:Start Ref="o30"/>
</c:Object>
</o:StartSymbol>
<o:ActivitySymbol Id="o76">
<a:CreationDate>1382092364</a:CreationDate>
<a:ModificationDate>1382092385</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((12400,9860), (18399,11859))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o18"/>
</c:Object>
</o:ActivitySymbol>
<o:BaseSynchronizationSymbol Id="o73">
<a:CreationDate>1382092753</a:CreationDate>
<a:ModificationDate>1382092767</a:ModificationDate>
<a:Rect>((13929,20000), (15429,22740))</a:Rect>
<a:AutoAdjustToText>0</a:AutoAdjustToText>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>12615680</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>512</a:GradientFillMode>
<a:GradientEndColor>12615680</a:GradientEndColor>
<a:ManuallyResized>1</a:ManuallyResized>
<c:Object>
<o:Synchronization Ref="o16"/>
</c:Object>
</o:BaseSynchronizationSymbol>
<o:ActivitySymbol Id="o80">
<a:CreationDate>1382092965</a:CreationDate>
<a:ModificationDate>1382093348</a:ModificationDate>
<a:IconMode>-1</a:IconMode>
<a:Rect>((13320,-10360), (19319,-8361))</a:Rect>
<a:LineColor>12615680</a:LineColor>
<a:FillColor>16777152</a:FillColor>
<a:ShadowColor>12632256</a:ShadowColor>
<a:FontList>STRN 0 Arial,8,N
DISPNAME 0 Arial,8,N
LABL 0 Arial,8,N</a:FontList>
<a:BrushStyle>6</a:BrushStyle>
<a:GradientFillMode>65</a:GradientFillMode>
<a:GradientEndColor>16777215</a:GradientEndColor>
<c:Object>
<o:Activity Ref="o52"/>
</c:Object>
</o:ActivitySymbol>
</c:SubSymbols>
<c:Object>
<o:OrganizationUnit Ref="o68"/>
</c:Object>
</o:SwimlaneSymbol>
</c:SubSymbols>
</o:SwimlaneGroupSymbol>
</c:Symbols>
</o:ActivityDiagram>
</c:ActivityDiagrams>
<c:Starts>
<o:Start Id="o7">
<a:ObjectID>0A43070E-B941-4718-B27E-CE32A86E3CAA</a:ObjectID>
<a:Name>Debut_1</a:Name>
<a:Code>Debut_1</a:Code>
<a:CreationDate>1382089347</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089347</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Start>
<o:Start Id="o30">
<a:ObjectID>75CDEFE0-284D-4ADA-8C71-83AEFD99C9D8</a:ObjectID>
<a:Name>Debut_2</a:Name>
<a:Code>Debut_2</a:Code>
<a:CreationDate>1382092090</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092090</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:Start>
</c:Starts>
<c:Ends>
<o:End Id="o11">
<a:ObjectID>1841C960-40EA-4943-A72F-49D213B368BC</a:ObjectID>
<a:Name>Fin_1</a:Name>
<a:Code>Fin_1</a:Code>
<a:CreationDate>1382089849</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089849</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:End>
<o:End Id="o14">
<a:ObjectID>D5314224-4119-437B-9AA3-92015ECFF240</a:ObjectID>
<a:Name>Fin_2</a:Name>
<a:Code>Fin_2</a:Code>
<a:CreationDate>1382092088</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382092088</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
</o:End>
</c:Ends>
<c:TargetModels>
<o:TargetModel Id="o130">
<a:ObjectID>5C44E25E-DD08-4130-AC6B-249052B470FD</a:ObjectID>
<a:Name>C++</a:Name>
<a:Code>C++</a:Code>
<a:CreationDate>1382089323</a:CreationDate>
<a:Creator>ansel</a:Creator>
<a:ModificationDate>1382089323</a:ModificationDate>
<a:Modifier>ansel</a:Modifier>
<a:TargetModelURL>file:///%_OBJLANG%/C++.xol</a:TargetModelURL>
<a:TargetModelID>22FB523D-7E45-430F-8069-3A702CF3BE3C</a:TargetModelID>
<a:TargetModelClassID>1811206C-1A4B-11D1-83D9-444553540000</a:TargetModelClassID>
<c:SessionShortcuts>
<o:Shortcut Ref="o3"/>
</c:SessionShortcuts>
</o:TargetModel>
</c:TargetModels>
</o:Model>
</c:Children>
</o:RootObject>

</Model>