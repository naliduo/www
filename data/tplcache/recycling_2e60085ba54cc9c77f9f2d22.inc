<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>�ĵ�����վ</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>
<script language="javascript">
function moveArc(aid){
	var qstr=getCheckboxItem();
	if(aid==0) aid = getOneItem();
	location="archives_do.php?aid="+aid+"&dopost=return&qstr="+qstr;
}
function delArc(aid){
	var qstr=getCheckboxItem();
	if(aid==0) aid = getOneItem();
	location="archives_do.php?qstr="+qstr+"&aid="+aid+"&dopost=del&recycle=1";
}
//���ѡ���ļ����ļ���
function getCheckboxItem()
{
	var allSel="";
	if(document.form2.arcID.value) return document.form2.arcID.value;
	for(i=0;i<document.form2.arcID.length;i++)
	{
		if(document.form2.arcID[i].checked)
		{
			if(allSel=="")
				allSel=document.form2.arcID[i].value;
			else
				allSel=allSel+"`"+document.form2.arcID[i].value;
		}
	}
	return allSel;
}
//���ѡ������һ����id
function getOneItem()
{
	var allSel="";
	if(document.form2.arcID.value) return document.form2.arcID.value;
	for(i=0;i<document.form2.arcID.length;i++)
	{
		if(document.form2.arcID[i].checked)
		{
				allSel = document.form2.arcID[i].value;
				break;
		}
	}
	return allSel;
}
function selAll()
{
	for(i=0;i<document.form2.arcID.length;i++)
	{
		if(!document.form2.arcID[i].checked)
		{
			document.form2.arcID[i].checked=true;
		}
	}
}
function noSelAll()
{
	for(i=0;i<document.form2.arcID.length;i++)
	{
		if(document.form2.arcID[i].checked)
		{
			document.form2.arcID[i].checked=false;
		}
	}
}
</script>
<style>
.coolbg2 {
border: 1px solid #000000;
background-color: #F2F5E9;
height:18px
}
.coolbt2 {
  border-left: 2px solid #EFEFEF;
  border-top: 2px solid #EFEFEF;
  border-right: 2px solid #ACACAC;
  border-bottom: 2px solid #ACACAC;
  background-color: #F7FCDA
}
.nbline {border-bottom: 1px solid #d6d6d6; background-color:#FFFFFF; }
.bline2 {border-bottom: 1px solid #d6d6d6; background-color:#F9FCEF; }
</style>
</head>
<body onLoad="ContextMenu.intializeContextMenu()">

<div id="main-content">
<script language="javascript">
$("#articles").addClass("current");$("#recycling").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>�ĵ�����վ</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" cellpadding="2" cellspacing="1" bgcolor="#cfcfcf" align="center">

<form name="form2">
<tr align="center" bgcolor="#FBFCE2" height="25">
<td width="6%">ID</td>
<td width="4%">ѡ��</td>
<td width="28%">���±���</td>
<td width="10%">����ʱ��</td>
<td width="10%">��Ŀ</td>
<td width="8%">���</td>
<td width="10%">����</td>
</tr>
<?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
<tr align='center' bgcolor="#FFFFFF"  onMouseMove="javascript:this.bgColor='#FCFDEE';" onMouseOut="javascript:this.bgColor='#FFFFFF';"
	height="25" oncontextmenu="ShowMenu(event,this,<?php echo $fields['id']; ?>,'<?php echo urlencode($fields['title']); ?>')">
<td><?php echo $fields['id']; ?></td>
<td><input name="arcID" type="checkbox" id="arcID" value="<?php echo $fields['id']; ?>" class="np"></td>
<td align='left'>
	<a href='archives_do.php?aid=<?php echo $fields['id']; ?>&dopost=editArchives'><u><?php echo $fields['title']; ?></u></a>
</td>
<td><?php echo GetDateMk($fields['senddate']); ?></td>
<td><?php echo $fields['typename']; ?></td>
<td><?php echo $fields['click']; ?></td>
<td><a href="javascript:moveArc(<?php echo $fields['id']; ?>)">��ԭ</a> | <a href="javascript:delArc(<?php echo $fields['id']; ?>)">ɾ��</a></td>
</tr>
<?php
}
}?>
<tr bgcolor="#ffffff">
<td height="24" colspan="7">
&nbsp;
  <input class="button" onclick="javascript:selAll()" type="button" value="ȫѡ" />
<input class="button" onclick="javascript:noSelAll()" type="button" value="ȡ��" />
<input class="button" onclick="javascript:moveArc()" type="button" value="��ԭ" />
<input class="button" onclick="javascript:delArc()" type="button" value="ɾ��" />

</td>
</tr>
</form>
<tr align="right" bgcolor="#F9FCEF">
<td height="30" colspan="7" align="center">
	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '3';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</td>
</tr>
</table>
							
							<div class="clear"></div><!-- End .clear -->
							
						
						
					</div> <!-- End #tab1 -->

					
				</div> <!-- End .content-box-content -->
				
			</div> <!-- End .content-box -->
			
			<div class="clear"></div>
			
           <?php include(DEDEADMIN.'/templets/footer.htm'); ?>
			
		</div> <!-- End #main-content -->	
	</div>
</body>
</html>