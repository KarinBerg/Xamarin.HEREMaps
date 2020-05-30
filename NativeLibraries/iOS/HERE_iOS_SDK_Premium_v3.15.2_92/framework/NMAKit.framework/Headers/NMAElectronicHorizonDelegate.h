/*
 * Copyright (c) 2011-2020 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAElectronicHorizon;
@class NMAEHPathTree;
@class NMAEHLink;
@class NMAEHPosition;


/**
 * An interface for responding to electronic horizon events sent by the
 * NMAElectronicHorizon.
 */
@protocol NMAElectronicHorizonDelegate<NSObject>
@optional

/**
 * Guaranteed to be called after updating electronic horizon when a valid map matched
 * position is available.
 *
 * @param electronicHorizon The `NMAElectronicHorizon` instance.
 * @param position Updated position which contains the most probable path which we are
 * currently on and the offset from its origin or an offroad position otherwise.
 */
- (void)electronicHorizon:(nonnull NMAElectronicHorizon *)electronicHorizon
    didReceiveNewPosition:(nonnull NMAEHPosition *)position;

/**
 * Called every time when the tree is reset.
 *
 * @param electronicHorizon The `NMAElectronicHorizon` instance.
 *
 * @note A tree reset occurs when the new position cannot be matched to the expected main
 * path or one of it's side paths. The tree will be rebuilt based on the new position.
 */
- (void)electronicHorizonDidReceiveTreeReset:(nonnull NMAElectronicHorizon *)electronicHorizon;

/**
 * Called every time a new link is added to the tree.
 *
 * @param electronicHorizon The `NMAElectronicHorizon` instance.
 * @param pathTree The path to which the link was added.
 * @param link The link which was added.
 */
- (void)electronicHorizon:(nonnull NMAElectronicHorizon *)electronicHorizon
      didReceiveLinkAdded:(nonnull NMAEHPathTree *)pathTree
                     link:(nonnull NMAEHLink *)link
NS_SWIFT_NAME(electronicHorizon(_:didReceiveLinkAdded:_:));

/**
 * Called when a link is removed from the tree.
 *
 * @note This is not called when the link was already removed as a result of
 * `electronicHorizon:didReceivePathRemoved:`.
 *
 * @param electronicHorizon The `NMAElectronicHorizon` instance.
 * @param pathTree The path from which the link will be removed.
 * @param link The link which will be removed.
 */
- (void)electronicHorizon:(nonnull NMAElectronicHorizon *)electronicHorizon
    didReceiveLinkRemoved:(nonnull NMAEHPathTree *)pathTree
                     link:(nonnull NMAEHLink *)link
NS_SWIFT_NAME(electronicHorizon(_:didReceiveLinkRemoved:_:));

/**
 * Called every time a new path is added to the tree.
 *
 * @param electronicHorizon The `NMAElectronicHorizon` instance.
 * @param pathTree The path which was added.
 */
- (void)electronicHorizon:(nonnull NMAElectronicHorizon *)electronicHorizon
      didReceivePathAdded:(nonnull NMAEHPathTree *)pathTree;

/**
 * Called every time a path is removed from the tree.
 *
 * @param electronicHorizon The `NMAElectronicHorizon` instance.
 * @param pathTree The path which will be removed.
 *
 * @note No additional events about removing will be fired
 * for children and links of this path.
 */
- (void)electronicHorizon:(nonnull NMAElectronicHorizon *)electronicHorizon
    didReceivePathRemoved:(nonnull NMAEHPathTree *)pathTree;

/**
 * Called every time a path is detached from its parent.
 *
 * @note The detached child is expected to become the new main path, as the
 * vehicle's position could still be matched on the tree.
 *
 * @param electronicHorizon The `NMAElectronicHorizon` instance.
 * @param parent The parent path tree.
 * @param child The child path tree.
 */
- (void)electronicHorizon:(nonnull NMAElectronicHorizon *)electronicHorizon
  didReceiveChildDetached:(nonnull NMAEHPathTree *)parent
                    child:(nonnull NMAEHPathTree *)child
NS_SWIFT_NAME(electronicHorizon(_:didReceiveChildDetached:_:));

@end
