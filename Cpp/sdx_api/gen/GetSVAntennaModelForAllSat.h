#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SVAntennaModelForAllSat is deprecated since 21.3. You may use SVAntennaModelForEachSV.
    /// 
    /// Get the antenna model for all satellites.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetSVAntennaModelForAllSat;
    typedef std::shared_ptr<GetSVAntennaModelForAllSat> GetSVAntennaModelForAllSatPtr;
    
    
    class GetSVAntennaModelForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaModelForAllSat();

      GetSVAntennaModelForAllSat(const std::string& system);
  
      static GetSVAntennaModelForAllSatPtr create(const std::string& system);
      static GetSVAntennaModelForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

