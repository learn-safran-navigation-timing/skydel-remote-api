#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the list of enabled signals for a specified SV ID.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------
    /// System string The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId   int    The satellite SV ID.
    ///

    class GetEnabledSignalsForSV;
    typedef std::shared_ptr<GetEnabledSignalsForSV> GetEnabledSignalsForSVPtr;
    
    
    class GetEnabledSignalsForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEnabledSignalsForSV();

      GetEnabledSignalsForSV(const std::string& system, int svId);

      static GetEnabledSignalsForSVPtr create(const std::string& system, int svId);
      static GetEnabledSignalsForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

