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
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetSVAntennaModelForEachSV;
    typedef std::shared_ptr<GetSVAntennaModelForEachSV> GetSVAntennaModelForEachSVPtr;
    
    
    class GetSVAntennaModelForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaModelForEachSV();

      GetSVAntennaModelForEachSV(const std::string& system);

      static GetSVAntennaModelForEachSVPtr create(const std::string& system);
      static GetSVAntennaModelForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

