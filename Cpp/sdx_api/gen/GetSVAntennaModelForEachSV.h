#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the antenna model for all satellites.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class GetSVAntennaModelForEachSV;
    typedef std::shared_ptr<GetSVAntennaModelForEachSV> GetSVAntennaModelForEachSVPtr;
    
    
    class GetSVAntennaModelForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSVAntennaModelForEachSV();

      GetSVAntennaModelForEachSV(const std::string& system);

      static GetSVAntennaModelForEachSVPtr create(const std::string& system);
      static GetSVAntennaModelForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

