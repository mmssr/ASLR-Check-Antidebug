# ASLR-Check-Antidebug

Small crummy ChatGPT POC for an antidebug technique to check if ASLR is disabled on a binary. Malware analysts will frequently disable ASLR before debugging. Disabling ASLR ensures that memory addresses referenced within the binary remain consistent across runs. Disabling ASLR makes debugging easier by providing a consistent memory layout for analysis and debugging tools.
