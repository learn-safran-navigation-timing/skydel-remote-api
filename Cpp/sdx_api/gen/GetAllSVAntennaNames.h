#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a list of all space vehicle antenna names.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class GetAllSVAntennaNames;
    typedef std::shared_ptr<GetAllSVAntennaNames> GetAllSVAntennaNamesPtr;
    
    
    class GetAllSVAntennaNames : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllSVAntennaNames();

      GetAllSVAntennaNames(const std::string& system);

      static GetAllSVAntennaNamesPtr create(const std::string& system);
      static GetAllSVAntennaNamesPtr dynamicCast(CommandBasePtr ptr);
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

