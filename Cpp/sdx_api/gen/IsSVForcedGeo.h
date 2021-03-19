#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a satellite is geostationary
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId   int    The satellite SV ID
    ///

    class IsSVForcedGeo;
    typedef std::shared_ptr<IsSVForcedGeo> IsSVForcedGeoPtr;
    
    
    class IsSVForcedGeo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSVForcedGeo();

      IsSVForcedGeo(const std::string& system, int svId);
  
      static IsSVForcedGeoPtr create(const std::string& system, int svId);
      static IsSVForcedGeoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

