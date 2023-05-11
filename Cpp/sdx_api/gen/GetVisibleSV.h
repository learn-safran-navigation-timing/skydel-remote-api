#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a list of visible satellites' SV IDs within a system, returns a GetVisibleSVResult
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------
    /// System string The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetVisibleSV;
    typedef std::shared_ptr<GetVisibleSV> GetVisibleSVPtr;
    
    
    class GetVisibleSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVisibleSV();

      GetVisibleSV(const std::string& system);

      static GetVisibleSVPtr create(const std::string& system);
      static GetVisibleSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

