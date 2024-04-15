#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set if spectrums are show/hide.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------
    /// Visible bool Show spectrum flag
    ///

    class SetSpectrumVisible;
    typedef std::shared_ptr<SetSpectrumVisible> SetSpectrumVisiblePtr;
    
    
    class SetSpectrumVisible : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpectrumVisible();

      SetSpectrumVisible(bool visible);

      static SetSpectrumVisiblePtr create(bool visible);
      static SetSpectrumVisiblePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** visible ****
      bool visible() const;
      void setVisible(bool visible);
    };
    
  }
}

