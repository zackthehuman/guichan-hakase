/*
 * Guichan Hakase Extensions
 *
 * Copyright (c) 2013 Hakase Labs
 *
 *
 * Zack Mulgrew a.k.a ZackTheHuman
 *
 * Visit: https://github.com/hakase-labs/guichan-hakase
 *
 * License: (BSD)
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Guichan nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef GCN_HIKARI_FUNCTORSELECTIONLISTENER_HPP
#define GCN_HIKARI_FUNCTORSELECTIONLISTENER_HPP

#include <functional>

#include "guichan/selectionlistener.hpp"
#include "guichan/platform.hpp"

namespace gcn
{
    typedef std::function<void (const SelectionEvent&)> SelectionListenerCallback;

    /**
     * Adapter for attaching a function to a Widget as an SelectionListener.
     *
     * @author Zack Mulgrew
     */
    class GCN_EXTENSION_DECLSPEC FunctorSelectionListener : public SelectionListener
    {
    public:

        /**
         * Constructor. Accepts a function object to call when selected
         * value changes. Defaults to no-op function.
         */
        explicit FunctorSelectionListener(const SelectionListenerCallback & callback = SelectionListenerCallback());

        /**
         * Destructor.
         */
        virtual ~FunctorSelectionListener() { }

        const SelectionListenerCallback& getCallback() const;

        /**
         * Sets the callback function, copies callback by value.
         */
        void setCallback(const SelectionListenerCallback & callback);

        /**
         * Sets the callback function, uses an rvalue reference.
         */
        void setCallback(const SelectionListenerCallback && callback);

        // Inherited from SelectionListener

        virtual void valueChanged(const SelectionEvent& selectionEvent);
    
    private:
        /**
         * Holds the function to call when action event is triggered.
         */
        SelectionListenerCallback mCallback;

    };
}

#endif // end GCN_HIKARI_FUNCTORSELECTIONLISTENER_HPP
