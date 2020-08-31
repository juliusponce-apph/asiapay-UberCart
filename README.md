# PayDollar/SiamPay/PesoPay Payment plugin for UberCart
Use PayDollar/SiamPay/PesoPays plugin for UberCart on Wordpress to offer ALL payments option.

## Integration
The plugin integrates integrate UberCart on Wordpress with PayDollar/SaimPay/PesoPay payment gateway with All payment method.

## Requirements
This plugin supports UberCart version 2 and higher.

## Installation
1. Follow the normal steps to install & activate this module.
   See http://www.ubercart.org/docs/user/10972/installing_contributed_modules
2. Go to "Administer > Store administration > Configuration > Payment settings > Payment methods".
3. Enable the "PayDollar PayGate" under "Payment methods" section.
4. In the fieldset "PayDollar PayGate settings", enter your PayDollar merchant ID.
* (Optional) You can also change the Currency code, Language for checkout page, and the Order review submit button text.
* Don't forget to switch as "Live" PayDollar server when your site is ready for production.
5. The default Datafeed URL is "http://your.domain.com/uc_paydollar/datafeed". You should apply this URL from AsiaPay customer support service in order to modify your merchant account setting.

Once above setup correctly, end-user will able to checkout with PayDollar PayGate. They will be forward to PayDollar's Payment Connection Page in order to complete their payment with all registered payment method of merchant account. After finish the payment, the browser will be redirected back to the shopping cart and the payment status will be shown.

## Setup the Datafeed URL on PayDollar/PesoPay/SiamPay
 1. Login to your PayDollar/PesoPay/SiamPay account.
 2. After login, Go to left sidebar on Profile > Profile Settings > Payment Options.
 3. Click the “Enable” radio and set the datafeed URL on “Return Value Link” and click the “Update” button. The datafeed URL should be like this: http://www.yourdomain.com/index.php?wc-api=wc_paydollar
 4. On the confirmation page, review your changes then click the “Confirm button”.

## Support
If you have a feature request, or spotted a bug or a technical problem, create a GitHub issue. For other questions, contact our [Customer Service](https://www.paydollar.com/en/contactus.html).

## License
MIT license. For more information, see the LICENSE file.
