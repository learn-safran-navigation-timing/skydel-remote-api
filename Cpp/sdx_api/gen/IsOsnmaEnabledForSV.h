#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if OSNMA is enabled or disabled.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------------------------------------------
    /// SvId int  The satellite's SV ID (use 0 for all Galileo's satellites).
    ///

    class IsOsnmaEnabledForSV;
    typedef std::shared_ptr<IsOsnmaEnabledForSV> IsOsnmaEnabledForSVPtr;
    
    
    class IsOsnmaEnabledForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsOsnmaEnabledForSV();

      IsOsnmaEnabledForSV(int svId);

      static IsOsnmaEnabledForSVPtr create(int svId);
      static IsOsnmaEnabledForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

