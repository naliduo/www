<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>�Զ����������</title>

<link rel="stylesheet" href="css/reset.css" type="text/css" media="screen" />
<link rel="stylesheet" href="css/style.css" type="text/css" media="screen" />
<link rel="stylesheet" type="text/css" href="css/base.css">
<script language="javascript" src="js/jquery.min.js" type="text/javascript"></script>	
<script type="text/javascript" src="js/admin.jquery.configuration.js"></script>

<script language="javascript" src="js/global.js"></script>
<script language="javascript" src="../include/js/dedeajax2.js"></script>
</head>
<body>

<div id="main-content">
<script language="javascript">
$("#channel").addClass("current");$("#diy_main").addClass("current");</script>				

	<div class="content-box"><!-- Start Content Box -->
				
				<div class="content-box-header">
					
					<h3>�Զ����������</h3>
					
					<ul class="content-box-tabs">

					</ul>
					
					<div class="clear"></div>
					
				</div> <!-- End .content-box-header -->
				
				<div class="content-box-content">
					
<div class="tab-content  default-tab" id="tab1">				
<table width="98%" border="0" cellpadding="1" cellspacing="1" align="center" class="tbtitle" style="border:1px solid #CFCFCF;border-bottom:none;">
		<tr>
				<td class="tbtitletxt">
				  <table width='96%' border="0" cellpadding='0' cellspacing='0'>
                  <tr>
                    <td width='30%' style="padding-left:10px;">[<a href="diy_add.php"><u>�����µ��Զ������</u></a>]</td>
                    <td align='right'>
						[ͼƬ˵����
						<img src='images/manage1.gif' valign="middle"alt='����' />����
						<img src='images/file_del.gif' valign="middle" alt='ɾ��' />ɾ��
						]
                   </td>
                  </tr>
         </table>
      </td>
  </tr>
</table>

<table width="98%" border="0" cellpadding="1" cellspacing="1" align="center" class='tbtitle' style='background:#CFCFCF;margin-bottom:5px;'>
		<tr align="center" bgcolor="#FBFCE2" height="26">
         <td>diyid</td>
		  <td>����</td>
		  <td>����</td>
		  <td>����</td>
  </tr>
		   <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
		  <tr align="center" bgcolor="#FFFFFF" onMouseMove="javascript:this.bgColor='#FCFDEE';" onMouseOut="javascript:this.bgColor='#FFFFFF';">
        <td><?php echo $fields['diyid']; ?></td>
        <td><a href="diy_list.php?action=list&diyid=<?php echo $fields['diyid']; ?>"><u><?php echo $fields['name']; ?></u></a></td>
        <td><?php echo $fields['table']; ?></td>
        <td>
         <a href='diy_edit.php?diyid=<?php echo $fields['diyid']; ?>&dopost=edit'><img src='images/manage1.gif' alt='����' /></a> |
		     <a href='diy_edit.php?diyid=<?php echo $fields['diyid']; ?>&dopost=delete'><img src='images/file_del.gif' alt='ɾ��' /></a> |
		     <a href="../plus/diy.php?action=list&diyid=<?php echo $fields['diyid']; ?>" target="_blank"><img src='images/gtk-tmp.png' title='Ԥ��' alt='Ԥ��' />ǰ̨Ԥ��</a>
		    </td>
     </tr>
		   <?php
}
}?>
</table>


<table width="98%" border="0" cellpadding="5" cellspacing="1" align="center" style=" border:1px solid #CFCFCF;line-height:31px;margin:auto;">
		<tr>
			<td height="35" align="center" style="padding:7px 6px 6px 10px;" ><?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
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