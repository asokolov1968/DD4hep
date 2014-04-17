#include "DDRec/DetectorSurfaces.h"

namespace DD4hep {
  namespace DDRec {
    


    DetectorSurfaces::DetectorSurfaces(DD4hep::Geometry::DetElement const& e) : DetElement(e) , _sL( 0 ) {

      initialize() ;
    }
    
    DetectorSurfaces::~DetectorSurfaces(){
      // nothing to do: SurfaceList is added as extension
      // and is deleted automatically
    }
    
    
    void DetectorSurfaces::initialize() {
      
      DetElement det = *this ;
      
      const VolSurfaceList* vsL = volSurfaceList(det) ;

      try {

	_sL = det.extension< SurfaceList >() ;

      } catch( std::runtime_error e){ 
	
	_sL = det.addExtension<SurfaceList >(  new SurfaceList( true )  ) ; 
      }

      if( ! vsL->empty() ) {
	
	// std::cout <<  "     detector  " << det.name() << " id: " << det.id() << " has " <<  vsL->size() << " surfaces "  << std::endl ;
	
	// std::cout << " ------------------------- " 
	// 	  << " 	DetectorSurfaces::initialize()  adding surfaces : " 
	// 	  << std::endl ;
	
	for( VolSurfaceList::const_iterator it = vsL->begin() ; it != vsL->end() ; ++it ){
	  
	  VolSurface volSurf =  *it ;
	  
	  Surface* surf = new Surface(  det,  volSurf ) ;
	  
	  // std::cout << " ------------------------- " 
	  // 	    << " surface: "   << *surf        << std::endl
	  // 	    << " ------------------------- "  << std::endl ;
	  
	  
	  _sL->push_back( surf ) ;
	  
	}


      }

    }
    


  } // namespace
}// namespace