#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a satellite is enabled or disabled for this constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------------
    /// System string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId   int    The satellite's SV ID (use 0 for all SVs).
    ///

    class IsSVEnabled;
    typedef std::shared_ptr<IsSVEnabled> IsSVEnabledPtr;
    
    
    class IsSVEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSVEnabled();

      IsSVEnabled(const std::string& system, int svId);

      static IsSVEnabledPtr create(const std::string& system, int svId);
      static IsSVEnabledPtr dynamicCast(CommandBasePtr ptr);
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

