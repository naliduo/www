<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>�������</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>
<script language="javascript">
function LoadHashCode()
{
	var tgobj = document.getElementById('modulcode');
	var email = document.form1.email.value;
	var modulname = document.form1.modulname.value;
	var myajax = new DedeAjax(tgobj,false,true,'-','-','...');

   <?php
   if(strtolower(substr($cfg_soft_lang, 0, 3)) == 'utf') {
   ?>
   myajax.AddKeyUtf8('action','gethash');
   myajax.AddKeyUtf8('email',email);
   myajax.AddKeyUtf8('modulname',modulname);
   myajax.SendPost2('module_make.php');
   <?php
   }
   elseif (strtolower(substr($cfg_soft_lang, 0, 2)) == 'gb') {
   	 echo 'myajax.SendGet2("module_make.php?action=gethash&email="+email+"&modulname="+modulname);';
   }
   ?>

	//myajax.SendGet2('module_make.php?action=gethash&email='+email+'&modulname='+modulname);
	DedeXHTTP = null;
}
function ShowHideField(cbox,vid,nid)
{
	var cboxobj = document.getElementById(cbox);
	if(cboxobj.checked)
	{
		document.getElementById(nid).style.display = 'block';
		document.getElementById(vid).style.display = 'none';
	}
	else
	{
		document.getElementById(nid).style.display = 'none';
		document.getElementById(vid).style.display = 'block';
	}
}
function ShowHideMb(rbox1,nid)
{
	var rboxobj = document.getElementById(rbox1);
	if(rboxobj.checked)
	{
		document.getElementById(nid).style.display = 'none';
	}
	else
	{
		document.getElementById(nid).style.display = 'block';
	}
}
</script>
</head>
<body>

<div id="main-content">
<script language="javascript">
$("#plus").addClass("current");$("#plus_main").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>�������</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" align="center" cellpadding="3" cellspacing="1" bgcolor="#D6D6D6">
  <tr> 
    <td height="25" colspan="5" style="padding-left:10px;">

    	  [<a href="module_main.php?moduletype=plus"><u>��װ�²��</u></a>]


    </td>
  </tr>
  <tr align="center" bgcolor="#FBFCE2" height="24"> 
      <td width="10%">ID��</td>
      <td width="40%">�������</td>
      <td width="20%">�������</td>
      <td width="30%">����</td>
   </tr>
   <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
    <tr align="center" bgcolor="#FFFFFF" height="26" align="center" onMouseMove="javascript:this.bgColor='#FCFDEE';" onMouseOut="javascript:this.bgColor='#FFFFFF';"> 
        <td><?php echo $fields['aid']; ?></td>
        <td><?php echo $fields['plusname']; ?></td>
        <td><?php echo $fields['writer']; ?></td>
        <td><?php echo GetSta($fields['isshow'],$fields['aid'],$fields['plusname']); ?></td>
     </tr>
		<?php
}
}?>
     <tr align="center" bgcolor="#F9FCEF" height="36"> 
      <td colspan="5">
      	<?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

      </td>
     </tr>
   </table>
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