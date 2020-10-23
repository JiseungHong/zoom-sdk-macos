# Zoom MacOS Software Development Kit (SDK)
<div align="center">
<img src="https://s3.amazonaws.com/user-content.stoplight.io/8987/1541013063688" width="400px" max-height="400px" style="margin:auto;"/>
</div>

## Table of Contents   
- [Latest SDK News](#latest-sdk-news)   
- [Full Documentation && Community Support](#full-documentation-community-support)   
- [What is Zoom Mac SDK?](#what-is-zoom-mac-sdk)   
- [Disclaimer](#disclaimer)   
- [Getting Started](#getting-started)   
  - [Prerequisites](#prerequisites)   
  - [Installing](#installing)   
- [Documentation](#documentation)   
- [Navigating SDK sample files](#navigating-sdk-sample-files)   
- [SDK Reference](#sdk-reference)   
- [Versioning](#versioning)   
- [Change log](#change-log)   
- [Frequently Asked Questions (FAQ)](#frequently-asked-questions-faq)   
- [Support](#support)   
- [License](#license)   
- [Acknowledgments](#acknowledgments)   

## Latest SDK News
1. Starting from Client SDK 5.0, if you are using tokens to start a meeting, you will only need to retrieve ZAK from Zoom API. The user token has been deprecated. 
2. To follow with Zoom client's recent changes, Zoom SDK has temporary remove the "Unmute All" interface in Client SDK 5.0.
3. To align with Zoom’s [recent announcement](https://blog.zoom.us/wordpress/2020/04/22/zoom-hits-milestone-on-90-day-security-plan-releases-zoom-5-0/) pertaining to our security initiative, Zoom Client SDKs have added **AES 256-bit GCM encryption** support, which provides more protection for meeting data and greater resistance to tampering. **The system-wide account enablement of AES 256-bit GCM encryption will take place on June 01, 2020.** You are **strongly recommended** to start the required upgrade to this latest version 4.6.21666.0427 at your earliest convenience. Please note that any Client SDK versions below 4.6.21666.0427 will **no longer be operational** from June 01.
4. When you are deploying your app with Zoom macos SDK, please don't forget to re-sign the frameworks in `ZoomSDK` and please don't re-sign the files in `Plugins`.
5. Due to the enhanced security requirements added in Mac OS 10.14, if you are planning to use Mac OS SDK in Mac OS 10.14 or above, please add **Camera** and **Microphone** privacy settings in your `.plist` file.
6. **Unfortunately, our Mac OS SDK does not support Xcode 11 and publish to Mac App Store at this point. Please do not compile and build your application with Xcode 11. We are working on the Xcode 11 support and it is a priority for us. Pardon the inconvenience. Until then, please use Xcode 10 and here are the options for installing or using Xcode 10:**
   * [Working with multiple versions of Xcode](https://medium.com/@hacknicity/working-with-multiple-versions-of-xcode-e331c01aa6bc).  Make sure to follow instructions carefully, before launching for the first time.
   * Use a [hosted service](https://support.macincloud.com/support/solutions/articles/8000042681-how-to-utilize-a-different-xcode-version-for-build-process-on-mac) supporting [many versions of Xcode](https://support.macincloud.com/support/solutions/articles/8000023177-versions-of-tools-and-applications-on-vsts-agent-plan-servers-).

## Full Documentation && Community Support
You can find the full Zoom MacOS SDK documentation and the community support forum here:
<div align="center">
   <a target="_blank" href="https://marketplace.zoom.us/docs/sdk/native-sdks/macos" style="text-decoration:none">
   <img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/Doc-button.png" width="350px" max-height="350px" style="margin:1vh 1vw;"/>
   </a>
   <a target="_blank" href="https://devforum.zoom.us/c/desktop-sdk" style="text-decoration:none">
   <img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/Forum-button.png" width="350px" max-height="350px" style="margin:1vh 1vw;"/>
   </a>
</div>

## What is Zoom Mac SDK?
Zoom SDK makes it easy to integrate Zoom with your MacOS applications, and boosts up your applications with the power of Zoom.

* **Easy to use**: Our SDK is built to be easy to use. Just import the libraries, call a few functions, and we will take care all video conferencing related stuffs for you.
* **Localizable**: Our SDK naturally supports [multiple major languages](https://support.zoom.us/hc/en-us/articles/209982306-Change-your-language-on-Zoom), and you can add more to grow your applications internationally.
* **Custom Meeting UI**: If you want to add your own decorations to your Zoom meeting rooms, try our Custom UI feature to make your meeting room special.

## Disclaimer

**Please be aware that all hard-coded variables and constants shown in the documentation and in the demo, such as Zoom Token, Zoom Access, Token, etc., are ONLY FOR DEMO AND TESTING PURPOSES. We STRONGLY DISCOURAGE the way of HARDCODING any Zoom Credentials (username, password, API Keys & secrets, SDK keys & secrets, etc.) or any Personal Identifiable Information (PII) inside your application. WE DON’T MAKE ANY COMMITMENTS ABOUT ANY LOSS CAUSED BY HARD-CODING CREDENTIALS OR SENSITIVE INFORMATION INSIDE YOUR APP WHEN DEVELOPING WITH OUR SDK**.

## Getting Started

The following instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
* For detailed instructions, please refer to our documentation website: [https://marketplace.zoom.us/docs/sdk/native-sdks/macos](https://marketplace.zoom.us/docs/sdk/native-sdks/macos);
* If you need support or assistance, please visit our [Zoom Developer Community Forum](https://devforum.zoom.us/);

### Prerequisites

Before you try out our SDK, you would need the following to get started:

* **A Zoom Account**: If you do not have one, you can sign up at [https://zoom.us/signup](https://zoom.us/signup).
  * Once you have your Zoom Account, sign up for a 60-days free trial at [https://marketplace.zoom.us/](https://marketplace.zoom.us/)
* **A device with Mac OS**:
  * OS: MacOS 10.6 or later.
  * Xcode 10

**Note**: macOS SDK does not support publishing to Apple mac Store


### Installing

Clone or download a copy of our SDK files from GitHub. After you unzipped the file, you should have the following folders:

```
.
├── CHANGELOG.md
├── LICENSE.md
├── Plugins
├── README.md
├── SDK\ Resources
├── ZoomSDK
├── [ZoomSDKSample] <-- demo app is inside
└── version.txt
```
Once you have the files ready, please following the instructions to build and run your demo app: [https://marketplace.zoom.us/docs/sdk/native-sdks/macos](https://marketplace.zoom.us/docs/sdk/native-sdks/macos).

### Initializing SDK with JWT token
When initializing the SDK, you will need to compose a JWT token using your SDK key & secret.

* How to compose JWT token for SDK initialization

You may generate your JWT token using the online tool https://jwt.io/. **It is highly recommended to generate your JWT token in your backend server.**

JWT is generated with three core parts: Header, Payload, and Signature. When combined, these parts are separated by a period to form a token: aaaaa.bbbbb.cccc.

Please follow this template to compose your payload for SDK initialization:

** Header
```
{
  "alg": "HS256",
  "typ": "JWT"
}
```
** Payload
```
{
         "appKey": "string",     // Your SDK key
         "iat": long,   // access token issue timestamp (unit: second)
         "exp": long,  // access token expire timestamp, MAX: iat + 2 days (unit: second)
         "tokenExp": long // token expire timestamp, MIN:iat + 30 minutes (unit: second)
}
```
**The minimum value of `tokenExp` should be at least 30 minutes, otherwise, SDK will reject the authentication request.**
** Signature
```
HMACSHA256(
  base64UrlEncode(header) + "." +
  base64UrlEncode(payload),
  "Your SDK secret here"
)
```
You do not need to secret base64 encoded your signature. Once the JWT token is generated, please do not reveal it or publish it. **It is highly recommended to handle your SDK key and secret and generate JWT in a backend server to be consumed by your application. Do not generate JWT in a production application.**

## Documentation

Please visit [[https://marketplace.zoom.us/docs/sdk/native-sdks/macos](https://marketplace.zoom.us/docs/sdk/native-sdks/macos)] for details of each features and functions.

## Navigating SDK sample files

The following table provides the link to the implementation of each features in our demo app:

| UI mode            | Feature                                                      | Corresponding sample files                                   |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Essential features | SDK Initialization & Authentication                          | * [ZMSDKInitHelper.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/Init/ZMSDKInitHelper.m) <br />* [ZMSDKAuthHelper.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/Auth/ZMSDKAuthHelper.m) |
|                    | Authenticate with Zoom REST API and start a meeting as API user | * [ZMSDKRestAPILogin.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/Login/ZMSDKRestAPILogin.m) <br />* [ZMSDKApiMeetingInterface.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/StartJoinMeeting/ZMSDKApiMeetingInterface.m) |
|                    | Login with email & password                                  | * [ZMSDKEmailLogin.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/Login/ZMSDKEmailLogin.m) <br />* [ZMSDKDelegateMgr.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/ZMSDKDelegateMgr.m) |
|                    | Login with SSO token                                         | * [ZMSDKSSOLogin.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/Login/ZMSDKSSOLogin.m) <br />* [ZMSDKDelegateMgr.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/ZMSDKDelegateMgr.m) |
|                    | Start an instant meeting(For Logged-in user)                 | * [ZMSDKEmailMeetingInterface.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/StartJoinMeeting/ZMSDKEmailMeetingInterface.m) <br />* [ZMSDKSSOMeetingInterface.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/StartJoinMeeting/ZMSDKSSOMeetingInterface.m) |
|                    | Join a meeting                                               | * [ZMSDKJoinOnly.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/Login/ZMSDKJoinOnly.m) |
|                    | Schedule a meeting (For logged-in user)                      | * [ZMSDKScheduleWindowCtr.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/UI%20Interface/ZoomSDKScheduleWindowCtr.m) |
|                    | Settings                                                     | * [ZMSDKSettingWindowController.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/UI%20Interface/ZMSDKSettingWindowController.m) |
| Custom UI          | Video view                                                   | * [ZMSDKMeetingMainWindowController.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/UI%20Interface/ZMSDKMeetingMainWindowController.m) |
|                    | Thumbnail View                                               | * [ZMSDKThumbnailView.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/UI%20Interface/ZMSDKThumbnailView.m) <br />* [ZMSDKThumbnailVideoItemView.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/ZMSDKThumbnailVideoItemView.m) |
|                    | Share View                                                   | * [ZMSDKShareSelectWindow.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/UI%20Interface/ZMSDKShareSelectWindow.m) |
|                    | Panelist View                                                | * [ZMSDKHCPanelistsView.m](https://github.com/zoom/zoom-sdk-macos/blob/master/ZoomSDKSample/ZoomSDKSample/UI%20Interface/ZMSDKHCPanelistsView.m) |

## SDK Reference

You may find the SDK interface reference at [https://marketplace.zoom.us/docs/sdk/native-sdks/macos/sdk-reference](https://marketplace.zoom.us/docs/sdk/native-sdks/macos/sdk-reference).
If you would like to get a local copy of the SDK reference, you may [download it here](https://github.com/zoom/zoom-sdk-macos/archive/gh-pages.zip).

## Versioning

For the versions available, see the [tags on this repository](https://github.com/zoom/zoom-sdk-macos/tags).

## Change log

Please refer to our [CHANGELOG](https://github.com/zoom/zoom-sdk-macos/blob/master/CHANGELOG.md) for all changes.

## Frequently Asked Questions (FAQ)
* 1️⃣ `SDK_Transcode.app`, `airhost.app`, and `aomhost.app` must be rebuilt with support for the Hardened Runtime...
  * When you are deploying your app with Zoom macos SDK, please don't forget to re-sign the frameworks in `ZoomSDK`. Append your own credentials onto the frameworks and try again.
* Please visit our [Zoom Developer Community Forum](https://devforum.zoom.us/) for further assistance.
* :two: `Unexpeceted service error: build aborted due to an internal error: unable to write manifest to ....: No such file or directory`
* Please change the Project settings at: File -> Project Settings -> Build Systems -> Legacy Build System and try again.

## Support

For any issues regarding our SDK, please visit our new Community Support Forum at https://devforum.zoom.us/.

## License

Use of this software is subject to important terms and conditions as set forth in the License file

Please refer to [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* :star: If you like our SDK, please give us a "Star". Your support is what keeps us moving forward and delivering happiness to you! Thanks a million! :smiley:
* If you need any support or assistance, we are here to help you: [Zoom Developer Community Forum](https://devforum.zoom.us/);

---
Copyright ©2020 Zoom Video Communications, Inc. All rights reserved.
