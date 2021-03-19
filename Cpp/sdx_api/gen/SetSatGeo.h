#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SatGeo is deprecated since 21.3. You may use ForceSVGeo.
    /// 
    /// Set whether a satellite is geostationary
    ///
    /// Name      Type   Description
    /// --------- ------ -----------------------------------------------------------------------------------------------------------------------------------------------
    /// System    string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// Prn       int    The satellite to make geostationary. Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// IsGeo     bool   True for geostationary satellite
    /// Longitude double The longitude to use, in degree
    ///

    class SetSatGeo;
    typedef std::shared_ptr<SetSatGeo> SetSatGeoPtr;
    
    
    class SetSatGeo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSatGeo();

      SetSatGeo(const std::string& system, int prn, bool isGeo, double longitude);
  
      static SetSatGeoPtr create(const std::string& system, int prn, bool isGeo, double longitude);
      static SetSatGeoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** isGeo ****
      bool isGeo() const;
      void setIsGeo(bool isGeo);


      // **** longitude ****
      double longitude() const;
      void setLongitude(double longitude);
    };
  }
}

