<?php

/*
ssh u781-dokrqb835gyy@dermaltherapy.com.au -p18765

git remote remove sg_dev
git remote remove sg_live

git remote add sg_dev ssh://u781-dokrqb835gyy@dermaltherapy.com.au:18765/home/u781-dokrqb835gyy/www/dev.dermaltherapy.com.au/dev.dermal.git
git remote add sg_live ssh://u781-dokrqb835gyy@dermaltherapy.com.au:18765/home/u781-dokrqb835gyy/www/dermaltherapy.com.au/live.dermal.git


global $user;


$ss = [
  "	Blue Click Collect	|	https://dermaltherapy.com.au/sites/all/themes/flexitol/images/blue-click-collect.png	|	1	",
  "	Coles	|	https://dermaltherapy.com.au/sites/default/files/coles-200x120.png	|	1	",
  "	Wollies	|	https://dermaltherapy.com.au/sites/default/files/wollies.png?e=r	|	1	",
  "	Chemist Wharehouse	|	https://dermaltherapy.com.au/sites/default/files/chemist-wharehouse_logo.png	|	1	",
  "	Priceline	|	https://dermaltherapy.com.au/sites/default/files/priceline.png	|	1	",
  "	Chemist Discount Centre	|	https://dermaltherapy.com.au/sites/default/files/chemist-discount-centre-logo.png	|	1	",
  "	Cincotta	|	https://dermaltherapy.com.au/sites/default/files/cincotta.png	|	1	",
  "	Discount Drug Store	|	https://dermaltherapy.com.au/sites/default/files/discount-drug-store_0.png	|	1	",
  "	Gppw	|	https://dermaltherapy.com.au/sites/default/files/field/image/gppw_logo_200_x_120_0.png	|	1	",
  "	Terry White	|	https://dermaltherapy.com.au/sites/default/files/terry-white_0.png	|	1	",
  "	Pharma Less	|	https://dermaltherapy.com.au/sites/default/files/pharma-less.png	|	1	",
  "	My Chemist	|	https://dermaltherapy.com.au/sites/default/files/my-chemist-logo.png	|	1	",
  "	Amcal	|	https://dermaltherapy.com.au/sites/default/files/field/image/amcal_logo_rgb_200x120_0.png	|	1	",
  "	Pharmacy Select	|	https://dermaltherapy.com.au/sites/default/files/pharmacy-select.png	|	1	",
  "	Blooms	|	https://dermaltherapy.com.au/sites/default/files/blooms_0.png	|	1	",
  "	Pharmasave	|	https://dermaltherapy.com.au/sites/default/files/pharmasave.png	|	1	",
  "	Shopsmart	|	https://dermaltherapy.com.au/sites/default/files/shopsmart.png	|	1	",
  "	National Pharmacies	|	https://dermaltherapy.com.au/sites/default/files/national-pharmacies.png	|	1	",
  "	Chemist King	|	https://dermaltherapy.com.au/sites/default/files/chemist_king-logo.png	|	1	",
  "	Soul Pattison	|	https://dermaltherapy.com.au/sites/default/files/soul-pattison.png	|	1	",
  "	Pharmacy Choice	|	https://dermaltherapy.com.au/sites/all/themes/flexitol/images/pharmacy-choice-logo.png	|	1	",
  "	Guradian	|	https://dermaltherapy.com.au/sites/default/files/guradian.png	|	1	",
  "	Optimal Pharmacy Plus	|	https://dermaltherapy.com.au/sites/all/themes/flexitol/images/optimal-pharmacy-plus.png	|	1	",
  "	Disconut Chemist	|	https://dermaltherapy.com.au/sites/default/files/disconut-chemist.png	|	1	",
  "	Yousave	|	https://dermaltherapy.com.au/sites/default/files/yousave.png	|	1	",
  "	Advantage	|	https://dermaltherapy.com.au/sites/default/files/advantage-logo.png	|	1	",
  "	Chempro	|	https://dermaltherapy.com.au/sites/default/files/chempro.png	|	1	",
  "	Chemsave	|	https://dermaltherapy.com.au/sites/default/files/chemsave.png	|	1	",
  "	Friendly Chemist	|	https://dermaltherapy.com.au/sites/default/files/friendly_chemist.png	|	1	",
  "	Giant Chemist	|	https://dermaltherapy.com.au/sites/default/files/giant_chemist.png	|	1	",
  "	Gregs	|	https://dermaltherapy.com.au/sites/default/files/gregs.png	|	1	",
  "	Ramsay	|	https://dermaltherapy.com.au/sites/default/files/ramsay.png	|	1	",
  "	Super Discount	|	https://dermaltherapy.com.au/sites/default/files/super_discount_0.png	|	1	",
  "	Superchem	|	https://dermaltherapy.com.au/sites/default/files/superchem_0.png	|	1	",
  "	United Chemist	|	https://dermaltherapy.com.au/sites/default/files/united_chemist.png	|	1	",
  "	Discount Chemist Online	|	https://dermaltherapy.com.au/sites/default/files/discountchemistonline.png	|	1	",
  "	Pharmacy Direct	|	https://dermaltherapy.com.au/sites/default/files/pharmacy-direct.png	|	1	",
  "	Pharmacy Online	|	https://dermaltherapy.com.au/sites/default/files/pharmacy-online.png	|	1	",
  "	Catch	|	https://dermaltherapy.com.au/sites/default/files/catch.png	|	1	",
  "	Discount Chemist	|	https://dermaltherapy.com.au/sites/default/files/discount_chemist.png	|	1	",
  "	Lake	|	https://dermaltherapy.com.au/sites/default/files/lake1.png	|	1	",
  "	Vital Pharmacy	|	https://dermaltherapy.com.au/sites/default/files/vital-pharmacy_0.png	|	1	",
  "	Amazon	|	https://dermaltherapy.com.au/sites/default/files/amazon-200_0.png	|	1	",
  "	Super Pharmacy	|	https://dermaltherapy.com.au/sites/default/files/field/image/superpharmacy_logo_0.png	|	1	",
  "	Chemist Outlet	|	https://dermaltherapy.com.au/sites/default/files/field/image/chemist_outlet_logo.png	|	1	",
  "	Life	|	https://dermaltherapy.com.au/sites/default/files/life.jpg	|	3	",
  "	Chemist Wharehouse	|	https://dermaltherapy.com.au/sites/default/files/chemist-wharehouse_logo.png	|	3	",
  "	Unichem	|	https://dermaltherapy.com.au/sites/default/files/unichem.jpg	|	3	",
  "	Pharmacy Direct	|	https://dermaltherapy.com.au/sites/default/files/pharmacy-direct.jpg	|	3	",
  "	Bargain Chemist	|	https://dermaltherapy.com.au/sites/default/files/bargain-chemist.png	|	3	",
  "	Guardian	|	https://dermaltherapy.com.au/sites/default/files/guardian_0.png	|	2	",
  "	Unity	|	https://dermaltherapy.com.au/sites/default/files/unity.png	|	2	",
  "	Watsons	|	https://dermaltherapy.com.au/sites/default/files/watsons.png	|	2	",
  "	Lazada	|	https://dermaltherapy.com.au/sites/default/files/lazada.png	|	2	",
  "	Shopee	|	https://dermaltherapy.com.au/sites/default/files/field/image/shopee2.png	|	2	",
];

foreach ($ss as $s) {
  $params = explode('|', $s);
  $title = trim($params[0]);
  $image = trim($params[1]);
  $domain = trim($params[2]);
  if ($domain == 1) {
    $domain_name = '[AU] ';
  }
  elseif ($domain == 2) {
    $domain_name = '[SG] ';
  }
  elseif ($domain == 3) {
    $domain_name = '[NZ] ';
  }

  $node = new stdClass();
  $node->title = $domain_name . $title;
  $node->type = "stockist";
  node_object_prepare($node);
  $node->language = LANGUAGE_NONE;
  $node->uid = $user->uid;
  $node->status = 0;
  $node->promote = 0;
  $node->comment = 0;
  $node->domains = array($domain => $domain);
  $node->domain_site = 0;



  $filename = basename($image);
  $image_object = file_get_contents($image);
  $file = file_save_data($image_object, 'public://stockist-' . $filename, FILE_EXISTS_RENAME);
  $file->uid = $user->uid;
  $node->field_image[$node->language][0] = (array)$file;


  $node = node_submit($node);
  node_save($node);

}
