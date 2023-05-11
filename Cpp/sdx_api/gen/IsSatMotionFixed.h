#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the satellite is fixed (True) or not fixed (false).
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId   int    The satellite's SV ID.
    ///

    class IsSatMotionFixed;
    typedef std::shared_ptr<IsSatMotionFixed> IsSatMotionFixedPtr;
    
    
    class IsSatMotionFixed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSatMotionFixed();

      IsSatMotionFixed(const std::string& system, int svId);

      static IsSatMotionFixedPtr create(const std::string& system, int svId);
      static IsSatMotionFixedPtr dynamicCast(CommandBasePtr ptr);
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

