#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSatMotionFixed.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------------------------------------------
    /// System  string "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId    int    The satellite's SV ID.
    /// IsFixed bool   If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.
    ///

    class IsSatMotionFixedResult;
    typedef std::shared_ptr<IsSatMotionFixedResult> IsSatMotionFixedResultPtr;
    
    
    class IsSatMotionFixedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSatMotionFixedResult();

      IsSatMotionFixedResult(const std::string& system, int svId, bool isFixed);

      IsSatMotionFixedResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isFixed);

      static IsSatMotionFixedResultPtr create(const std::string& system, int svId, bool isFixed);

      static IsSatMotionFixedResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isFixed);
      static IsSatMotionFixedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** isFixed ****
      bool isFixed() const;
      void setIsFixed(bool isFixed);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsSatMotionFixedResult);
  }
}

