#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set if map is show/hide in Analysis tab.
    ///
    /// Name Type Description
    /// ---- ---- -------------
    /// Show bool Show map flag
    ///

    class ShowMapAnalysis;
    typedef std::shared_ptr<ShowMapAnalysis> ShowMapAnalysisPtr;
    
    
    class ShowMapAnalysis : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ShowMapAnalysis();

      ShowMapAnalysis(bool show);

      static ShowMapAnalysisPtr create(bool show);
      static ShowMapAnalysisPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** show ****
      bool show() const;
      void setShow(bool show);
    };
    
  }
}

