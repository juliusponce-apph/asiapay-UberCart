<?php
// $Id: uc_paydollar.pages.inc,v 1.2 2011/01/25 08:20:25 hswong3i Exp $

/**
 * @file
 * PayDollar PayGate menu items.
 */

/**
 * Callback for Receive Instant Payment Notification with Success status.
 */
function uc_paydollar_success($order_id = 0) {
  watchdog('uc_paydollar', 'Receiving IPN with SUCCESS notification for order @order_id.', array(
    '@order_id' => $order_id,
  ));

  drupal_set_message('Your payment is SUCCESS on PayDollar', 'status');

  drupal_goto('cart');
}

/**
 * Callback for Receive Instant Payment Notification with Fail status.
 */
function uc_paydollar_fail($order_id = 0) {
  watchdog('uc_paydollar', 'Receiving IPN with FAIL notification for order @order_id.', array(
    '@order_id' => $order_id,
  ), WATCHDOG_ERROR);

  drupal_set_message('Your payment is FAIL on PayDollar', 'warning');

  drupal_goto('cart');
}

/**
 * Callback for Receive Instant Payment Notification with Cancel status.
 */
function uc_paydollar_cancel($order_id = 0) {
  watchdog('uc_paydollar', 'Receiving IPN with CANCEL notification for order @order_id.', array(
    '@order_id' => $order_id,
  ), WATCHDOG_ERROR);

  drupal_set_message('Your payment has been CANCELLED as user requested', 'warning');

  drupal_goto('cart');
}

/**
 * The Action when receive PayDollar detail datafeed.
 */
function uc_paydollar_datafeed() {
  $src = check_plain($_POST['src']);
  $prc = check_plain($_POST['prc']);
  $bank_ord = check_plain($_POST['Ord']);
  $holder = check_plain($_POST['Holder']);
  $successcode = check_plain($_POST['successcode']);
  $order_id = check_plain($_POST['Ref']);
  $paydollar_ref = check_plain($_POST['PayRef']);
  $amt = check_plain($_POST['Amt']);
  $cur = check_plain($_POST['Cur']);
  $cart_id = check_plain($_POST['remark']);
  $authid = check_plain($_POST['Authid']);
  $eci = check_plain($_POST['eci']);
  $payerauth = check_plain($_POST['payerAuth']);
  $sourceip = check_plain($_POST['sourceIp']);
  $ipcountry = check_plain($_POST['ipCountry']);
  $cdatetime = time();
  $mdatetime = $cdatetime;

  $order = uc_order_load($order_id);
  // variable for Ubercart
  $context = array(
    'revision' => 'formatted-original',
    'type' => 'amount',
  );
  $options = array(
    'sign' => FALSE,
  );

  if (!is_null($successcode)) {
    // Insert the datafeed into database
    db_query("INSERT INTO {uc_paydollar_datafeed} (src, prc, ord, holder, successcode, ref, payref, amt, cur, remark, authid, eci, payerauth, sourceip, ipcountry, cdatetime, mdatetime) VALUES (%d, %d, %d, '%s', %d, '%s', %d, %f, '%s', '%s', '%s', '%s', '%s', '%s', '%s', %d, %d)", $src, $prc, $bank_ord, $holder, $successcode, $order_id, $paydollar_ref, $amt, $cur, $cart_id, $authid, $eci, $payerauth, $sourceip, $ipcountry, $cdatetime, $mdatetime);
  }

  switch ($successcode) {
    Case 0:
      watchdog('uc_paydollar', 'Receiving PayDollar datafeed with SUCCESS notification for order @cart_id.', array(
        '@cart_id' => $cart_id,
      ));
      $comment = t('PayDollar transaction ID: @paydollar_ref', array('@paydollar_ref' => $paydollar_ref));
      uc_payment_enter($order_id, 'paydollar', $amt, $order->uid, NULL, $comment);

      // Empty that cart...
      uc_cart_empty($cart_id);

      // Complete a sale, including adjusting order status and creating user account.
      uc_cart_complete_sale($order);

      uc_order_comment_save($order_id, 0, t('Payment of @amount @cur submitted through PayDollar.', array('@amount' => uc_price($amt, $context, $options), '@cur' => $cur)), 'order', 'payment_received');
      uc_order_comment_save($order_id, 0, t('PayDollar IPN reported a payment of @amount @cur.', array('@amount' => uc_price($amt, $context, $options), '@cur' => $cur)));

      break;

    Case 1:
      watchdog('uc_paydollar', 'Receiving PayDollar datafeed with FAIL notification for order @cart_id.', array(
        '@cart_id' => $cart_id,
      ), WATCHDOG_ERROR);
      break;

    default:
      watchdog('uc_paydollar', 'Receiving PayDollar datafeed with OTHERS notification for order @cart_id.', array(
        '@cart_id' => $cart_id,
      ), WATCHDOG_ERROR);
      break;
  }

  // echo the page back to PayDollar
  print("OK\n");
  print("successcode = $successcode");
  exit(0);
}
