api = 2
core = 7.x
projects[drupal][version] = 7.x

; Patches for Core
; From Buildkit
projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch
; From Commerce
projects[drupal][patch][] = "http://drupal.org/files/issues/install-redirect-on-empty-database-728702-36.patch"
projects[drupal][patch][] = "http://drupal.org/files/drupal-1470656-14.patch"
projects[drupal][patch][] = "http://drupal.org/files/drupal-865536-204.patch"
projects[drupal][patch][] = "http://drupal.org/files/allow_change_system-requirements-1772316-4.patch"
projects[drupal][patch][] = "http://drupal.org/files/1275902-15-entity_uri_callback-D7.patch"