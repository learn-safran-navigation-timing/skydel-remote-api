#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) OSNMA for specified Galileo's satellite.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).
    /// Enabled bool OSNMA is enabled when value is True.
    ///

    class EnableOsnmaForSV;
    typedef std::shared_ptr<EnableOsnmaForSV> EnableOsnmaForSVPtr;
    
    
    class EnableOsnmaForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableOsnmaForSV();

      EnableOsnmaForSV(int svId, bool enabled);

      static EnableOsnmaForSVPtr create(int svId, bool enabled);
      static EnableOsnmaForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

