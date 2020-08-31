// $Id: README.txt,v 1.2 2011/01/25 08:20:25 hswong3i Exp $

ABOUT PAYDOLLAR PAYGATE FOR UBERCART
----------------------

This module integrate the AsiaPay PayDollar PayGate payment method with Drupal
6.x Ubercart 2.x. This module support the "Client Post Though Browser" payment
method, support dynamic language switch option, support connection though
testing or production URL, and so on.

Programming logic is originally cloned from official PayDollar osCommerce and
ZenCart modules implementation.

About AsiaPay PayDollar PayGate service:
  http://www.paydollar.com/
  http://www.paydollar.com/eng/paygate.htm

Developed by:
  http://pantarei-design.com/


INSTALLATION
----------------------

1. Follow the normal steps to install & activate this module.
   See http://www.ubercart.org/docs/user/10972/installing_contributed_modules

2. Go to "Administer > Store administration > Configuration > Payment settings
   > Payment methods".

3. Enable the "PayDollar PayGate" under "Payment methods" section.

4. In the fieldset "PayDollar PayGate settings", enter your PayDollar merchant
   ID.

  4.1. (Optional) You can also change the Currency code, Language for checkout
       page, and the Order review submit button text.

  4.2. Don't forget to switch as "Live" PayDollar server when your site is
       ready for production.

5. The default Datafeed URL is "http://your.domain.com/uc_paydollar/datafeed".
   You should apply this URL from AsiaPay customer support service in order to
   modify your merchant account setting.

Once above setup correctly, end-user will able to checkout with PayDollar
PayGate. They will be forward to PayDollar's Payment Connection Page in order
to complete their payment with all registered payment method of merchant
account. After finish the payment, the browser will be redirected back to the
shopping cart and the payment status will be shown.


LIST OF MAINTAINERS
----------------------

PROJECT OWNER
M: Edison Wong <hswong3i@gmail.com>
S: maintained
W: http://edin.no-ip.com/
