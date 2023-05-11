#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetAllSatellitesPseudorangeNoiseOffset is deprecated since 21.3. You may use GetPseudorangeNoiseOffsetForEachSV.
    /// 
    /// Get the satellite pseudorange noise constant offset for all satellites.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetAllSatellitesPseudorangeNoiseOffset;
    typedef std::shared_ptr<GetAllSatellitesPseudorangeNoiseOffset> GetAllSatellitesPseudorangeNoiseOffsetPtr;
    
    
    class GetAllSatellitesPseudorangeNoiseOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllSatellitesPseudorangeNoiseOffset();

      GetAllSatellitesPseudorangeNoiseOffset(const std::string& system);

      static GetAllSatellitesPseudorangeNoiseOffsetPtr create(const std::string& system);
      static GetAllSatellitesPseudorangeNoiseOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

