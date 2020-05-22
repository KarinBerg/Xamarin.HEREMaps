#!/bin/bash

#
# This script can be used to strip the simulator specifc architectures from the NMAKit library.
# The simulator architectures must be removed from NMAKit before it is included in an app which
# will be uploaded to the Apple Store.
#

VALID_ARCHS="armv7 arm64"
TARGET_FILE=NMAKit.framework/NMAKit
ARCHS="$(lipo -info ${TARGET_FILE} | rev | cut -d ':' -f1 | rev)"

echo "current archs are $ARCHS"
for ARCH in $ARCHS; do
    if ! [[ "${VALID_ARCHS}" == *"$ARCH"* ]]; then
        echo "stripping $ARCH"
        lipo -remove $ARCH -output $TARGET_FILE $TARGET_FILE || exit 1
    fi
done
echo "processed archs are $(lipo -info ${TARGET_FILE} | rev | cut -d ':' -f1 | rev)"
