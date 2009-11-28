# $Id: PKGBUILD 3138 2009-09-28 09:21:30Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm
pkgver=5.7.2
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11')
install=dwm.install
source=(http://code.suckless.org/dl/dwm/dwm-$pkgver.tar.gz \
	config.h)

build() {
  cd $srcdir/$pkgname-$pkgver

  cp $srcdir/config.h config.h

  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 || return 1
  make PREFIX=/usr DESTDIR=$pkgdir install || return 1

  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE && \
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
}
md5sums=('a0b8a799ddc5034dd8a818c9bd76f3a3'
         '92b0cf8178f12fa0308ba5e51418b649')
md5sums=('a0b8a799ddc5034dd8a818c9bd76f3a3'
         'ccf216b5d754a0440fa24dd028282e62')
md5sums=('a0b8a799ddc5034dd8a818c9bd76f3a3'
         'ef6e3ece9beaec2215ef341b685b1ec9')
md5sums=('a0b8a799ddc5034dd8a818c9bd76f3a3'
         'e6276fece357ad4812dc052d31147920')
