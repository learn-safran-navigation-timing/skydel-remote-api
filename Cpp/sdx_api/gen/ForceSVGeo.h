#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a satellite is geostationary
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------
    /// System    string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId      int    The satellite SV ID
    /// IsGeo     bool   True for geostationary satellite
    /// Longitude double The longitude to use, in degree
    ///

    class ForceSVGeo;
    typedef std::shared_ptr<ForceSVGeo> ForceSVGeoPtr;
    
    
    class ForceSVGeo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ForceSVGeo();

      ForceSVGeo(const std::string& system, int svId, bool isGeo, double longitude);
  
      static ForceSVGeoPtr create(const std::string& system, int svId, bool isGeo, double longitude);
      static ForceSVGeoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** isGeo ****
      bool isGeo() const;
      void setIsGeo(bool isGeo);


      // **** longitude ****
      double longitude() const;
      void setLongitude(double longitude);
    };
  }
}

