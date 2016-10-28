- meta:
    map: 'icrai'
    node: Entrance
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: Entrance_WayPoint2
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint2
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: Entrance_WayPoint5
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint5
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: Entrance
    pointset: icrai
    pose:
      orientation:
        w: 0.999796485747
        x: 0.0
        y: 0.0
        z: 0.0201739209973
      position:
        x: 0.0372942918875
        y: 0.00951023031754
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: DinningRoom
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: DinningRoom_WayPoint9
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint9
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: DinningRoom_Kitchen
      inflation_radius: 0.0
      map_2d: ''
      node: Kitchen
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: DinningRoom
    pointset: icrai
    pose:
      orientation:
        w: 0.812615275383
        x: 4.63094895764e-09
        y: 4.5655852432e-08
        z: 0.582800626755
      position:
        x: 3.82710838318
        y: 4.53496265411
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: Kitchen
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: Kitchen_DinningRoom
      inflation_radius: 0.0
      map_2d: ''
      node: DinningRoom
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: Kitchen_WayPoint12
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint12
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: Kitchen
    pointset: icrai
    pose:
      orientation:
        w: 0.996902287006
        x: 0.0
        y: 0.0
        z: 0.0786498934031
      position:
        x: 4.12509346008
        y: 2.59097409248
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint12
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint12_Kitchen
      inflation_radius: 0.0
      map_2d: ''
      node: Kitchen
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint12_WayPoint13
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint13
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint12
    pointset: icrai
    pose:
      orientation:
        w: 0.96294426918
        x: 7.79596387446e-09
        y: 1.31475130782e-09
        z: -0.269700884819
      position:
        x: 2.59976840019
        y: 1.76974463463
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint13
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint13_WayPoint2
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint2
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint13_WayPoint5
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint5
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint13_WayPoint12
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint12
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint13_Bathroom
      inflation_radius: 0.0
      map_2d: ''
      node: Bathroom
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WP13_WP15
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint15
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint13
    pointset: icrai
    pose:
      orientation:
        w: 0.996692895889
        x: 0.0
        y: 0.0
        z: 0.0812604129314
      position:
        x: 2.72133541107
        y: 0.198594897985
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: Bathroom
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: Bathroom_WayPoint13
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint13
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: Bathroom
    pointset: icrai
    pose:
      orientation:
        w: 0.893545276908
        x: 0.0
        y: 0.0
        z: -0.448973092863
      position:
        x: 4.0808034548
        y: 0.317011225437
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint15
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint15_MasterBedroom
      inflation_radius: 0.0
      map_2d: ''
      node: MasterBedroom
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WP15_WP13
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint13
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint15
    pointset: icrai
    pose:
      orientation:
        w: 0.71804612875
        x: 0.0
        y: 0.0
        z: 0.695995509624
      position:
        x: 3.14323043823
        y: -1.84270739555
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: MasterBedroom
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: MasterBedroom_WayPoint15
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint15
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: MasterBedroom
    pointset: icrai
    pose:
      orientation:
        w: 0.911656141281
        x: 1.13934550683e-08
        y: 1.24120740352e-08
        z: 0.410953879356
      position:
        x: 3.32868027687
        y: -3.85111284256
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint2
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint2_Entrance
      inflation_radius: 0.0
      map_2d: ''
      node: Entrance
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint2_WayPoint4
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint4
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint2_WayPoint5
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint5
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint2_WayPoint13
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint13
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint2
    pointset: icrai
    pose:
      orientation:
        w: 0.822144823203
        x: 0.0
        y: 0.0
        z: -0.569278393828
      position:
        x: 1.02840385111
        y: -0.530068829836
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: GuestBedroom
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: GuestBedroom_WayPoint4
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint4
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: GuestBedroom
    pointset: icrai
    pose:
      orientation:
        w: 0.780102126298
        x: 0.0
        y: 0.0
        z: 0.625652197747
      position:
        x: 0.248296503259
        y: -3.80249244767
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint4
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint4_WayPoint2
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint2
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint4_GuestBedroom
      inflation_radius: 0.0
      map_2d: ''
      node: GuestBedroom
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint4
    pointset: icrai
    pose:
      orientation:
        w: 0.831342003302
        x: 0.0
        y: 0.0
        z: 0.55576116592
      position:
        x: 1.14346084716
        y: -1.88521748657
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint5
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint5_Entrance
      inflation_radius: 0.0
      map_2d: ''
      node: Entrance
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint5_WayPoint2
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint2
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint5_WayPoint6
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint6
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint5_WayPoint13
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint13
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint5
    pointset: icrai
    pose:
      orientation:
        w: 0.682512289594
        x: 0.0
        y: 0.0
        z: 0.730874116763
      position:
        x: 1.17488527211
        y: 0.891508042064
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint6
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint6_WayPoint5
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint5
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint6_LivingRoom
      inflation_radius: 0.0
      map_2d: ''
      node: LivingRoom
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint6
    pointset: icrai
    pose:
      orientation:
        w: 0.768097995774
        x: 0.0
        y: 0.0
        z: -0.640332311294
      position:
        x: 1.07537456224
        y: 2.04645737438
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: Office
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: Office_LivingRoom
      inflation_radius: 0.0
      map_2d: ''
      node: LivingRoom
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: Office_WayPoint9
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint9
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: Office
    pointset: icrai
    pose:
      orientation:
        w: 0.713512420654
        x: -3.70480286449e-08
        y: -6.27015506183e-09
        z: 0.700642585754
      position:
        x: 1.15201079845
        y: 5.16771697998
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: LivingRoom
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: LivingRoom_WayPoint6
      inflation_radius: 0.0
      map_2d: ''
      node: WayPoint6
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: LivingRoom_Office
      inflation_radius: 0.0
      map_2d: ''
      node: Office
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: LivingRoom
    pointset: icrai
    pose:
      orientation:
        w: 0.999830245972
        x: 0.0
        y: 0.0
        z: 0.0184242911637
      position:
        x: -0.0252961218357
        y: 3.49904322624
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
- meta:
    map: 'icrai'
    node: WayPoint9
    pointset: icrai
  node:
    edges:
    - action: move_base
      edge_id: WayPoint9_Office
      inflation_radius: 0.0
      map_2d: ''
      node: Office
      recovery_behaviours_config: ''
      top_vel: 0.55
    - action: move_base
      edge_id: WayPoint9_DinningRoom
      inflation_radius: 0.0
      map_2d: ''
      node: DinningRoom
      recovery_behaviours_config: ''
      top_vel: 0.55
    localise_by_topic: ''
    map: 'icrai'
    name: WayPoint9
    pointset: icrai
    pose:
      orientation:
        w: 0.999881744385
        x: -1.79628507624e-08
        y: 7.23176585282e-09
        z: 0.0153769552708
      position:
        x: 2.47881293297
        y: 5.31017923355
        z: 0.0
    verts:
    - x: 0.689999997616
      y: 0.287000000477
    - x: 0.287000000477
      y: 0.689999997616
    - x: -0.287000000477
      y: 0.689999997616
    - x: -0.689999997616
      y: 0.287000000477
    - x: -0.689999997616
      y: -0.287000000477
    - x: -0.287000000477
      y: -0.689999997616
    - x: 0.287000000477
      y: -0.689999997616
    - x: 0.689999997616
      y: -0.287000000477
    xy_goal_tolerance: 0.3
    yaw_goal_tolerance: 0.1
